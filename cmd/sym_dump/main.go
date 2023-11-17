// The sym_dump tool converts Playstation 1 MND/SYM files to C headers (*.sym ->
// *.h) and scripts for importing symbol information into IDA.
package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"sort"

	"github.com/pkg/errors"
	"github.com/rickypai/natsort"
	"github.com/mefistotelis/psx_mnd_sym"
	"github.com/mefistotelis/psx_mnd_sym/csym"
	"github.com/mefistotelis/psx_mnd_sym/csym/c"
)

// usage prints usage information.
func usage() {
	const use = `
Convert PlayStation 1 MND/SYM files to C headers and/or Python scripts for importing symbol information into IDA.
`
	fmt.Println(use[1:])
	flag.PrintDefaults()
}

// Default output directory.
const dumpDir = "_dump_"

func main() {
	// Command line flags.
	var (
		// Output C types and declarations.
		outputC bool
		// Output directory.
		outputDir string
		// Output IDA scripts.
		outputIDA bool
		// Merge SYM files.
		merge bool
		// Split output into source files.
		splitSrc bool
		// Output C types.
		outputTypes bool
		// Verbosity level.
		opts sym.Options
	)
	flag.BoolVar(&outputC, "c", false, "output C types and declarations")
	flag.StringVar(&outputDir, "dir", dumpDir, "output directory")
	flag.BoolVar(&outputIDA, "ida", false, "output IDA scripts")
	flag.BoolVar(&merge, "merge", false, "merge SYM files")
	flag.BoolVar(&splitSrc, "src", false, "split output into source files")
	flag.BoolVar(&outputTypes, "types", false, "output C types")
	flag.BoolVar(&opts.Verbose, "v", false, "show verbose messages")
	flag.Usage = usage
	flag.Parse()

	if flag.NArg() == 0 {
		flag.Usage()
		return
	}

	if merge && outputIDA {
		log.Fatalf("IDA output not supported in merge mode, as the scripts would be unusable.")
	}

	// Parse SYM files.
	var ps []*csym.Parser
	for _, path := range flag.Args() {
		// Parse SYM file.
		f, err := sym.ParseFile(path, &opts)
		if err != nil {
			log.Fatalf("%+v", err)
		}

		var p *csym.Parser

		if outputC || outputIDA {
			// Parse C types and declarations.
			p = csym.NewParser(&opts)
			if merge {
				ps = append(ps, p)
			}
			p.ParseTypes(f.Syms)
			p.ParseDecls(f.Syms)
			p.RemoveDuplicateTypes()
			p.MakeNamesUnique()
		}

		if outputTypes {
			// Parse C types.
			p = csym.NewParser(&opts)
			if merge {
				ps = append(ps, p)
			}
			p.ParseTypes(f.Syms)
		}

		if outputC || outputIDA || outputTypes {
			// Output once for each files if not in merge mode.
			if !merge {
				if err := dump(p, outputDir, outputC, outputTypes, outputIDA, splitSrc, merge); err != nil {
					log.Fatalf("%+v", err)
				}
			}
			continue
		}

		// Output in Psy-Q DUMPSYM.EXE format.
		// Note, we never merge the Psy-Q output.
		fmt.Print(f)
	}
	// Output the merge of all files if in merge mode.
	if merge {
		skipAddrDiff := true
		skipLineDiff := true
		p := pruneDuplicates(ps, skipAddrDiff, skipLineDiff, &opts)
		if err := dump(p, outputDir, outputC, outputTypes, outputIDA, splitSrc, merge); err != nil {
			log.Fatalf("%+v", err)
		}
	}
}

// placeholder type name to make types match even when typename differ.
const placeholder = "placeholder"

// pruneDuplicates prunes duplicates declarations of the parser, optionally
// ignoring differences in address.
func pruneDuplicates(ps []*csym.Parser, skipAddrDiff, skipLineDiff bool, opts *sym.Options) *csym.Parser {
	dst := csym.NewParser(opts)
	enumPresent := make(map[string]bool)
	structPresent := make(map[string]bool)
	unionPresent := make(map[string]bool)
	typeDefPresent := make(map[string]bool)
	// Add unique predeclared identifiers.
	if def, ok := ps[0].Types["bool"]; ok {
		dst.Types["bool"] = def
	}

	fakeEnum := 0
	fakeStruct := 0
	fakeUnion := 0
	for pnum, p := range ps {
		addUniqueEnums(dst, p, pnum, &fakeEnum, &enumPresent, opts)
		addUniqueStructs(dst, p, pnum, &fakeStruct, &structPresent, opts)
		addUniqueUnions(dst, p, pnum, &fakeUnion, &unionPresent, opts)
		// Add unique typedefs.
		for _, def := range p.Typedefs {
			s := def.Def()
			if _, ok := typeDefPresent[s]; !ok {
				dst.Typedefs = append(dst.Typedefs, def)
			}
			typeDefPresent[s] = true
		}
	}

	// Sort types by tag.
	less := func(i, j int) bool {
		ti := dst.Typedefs[i].(*c.VarDecl)
		tj := dst.Typedefs[j].(*c.VarDecl)
		return natsort.Less(ti.Name, tj.Name)
	}
	sort.Slice(dst.Typedefs, less)

	varDeclPresent := make(map[string]bool)
	funcDeclPresent := make(map[string]bool)
	dstOverlays := make(map[uint32]*csym.Overlay)
	for _, p := range ps {
		// Add unique declarations of each overlay.
		overlays := append(p.Overlays, p.Overlay)
		for _, overlay := range overlays {
			curOverlay, ok := dstOverlays[overlay.ID]
			if !ok {
				curOverlay = &csym.Overlay{
					ID: overlay.ID,
				}
				dstOverlays[overlay.ID] = curOverlay
				if overlay.ID == p.Overlay.ID {
					if len(dst.Overlay.Vars) > 0 {
						panic("unreachable") // I hope :)
					}
					dst.Overlay = curOverlay
				} else {
					dst.Overlays = append(dst.Overlays, curOverlay)
				}
			}
			// Add unique variable declarations.
			for _, v := range overlay.Vars {
				origAddr := v.Addr
				if skipAddrDiff {
					v.Addr = 0
				}
				s := v.Def()
				if skipAddrDiff {
					v.Addr = origAddr
				}
				if !varDeclPresent[s] {
					curOverlay.Vars = append(curOverlay.Vars, v)
				}
				varDeclPresent[s] = true
			}
			// Add unique function declarations.
			for _, f := range overlay.Funcs {
				origAddr := f.Addr
				origLineStart := f.LineStart
				origLineEnd := f.LineEnd
				if skipAddrDiff {
					f.Addr = 0
				}
				if skipLineDiff {
					f.LineStart = 0
					f.LineEnd = 0
				}
				s := f.Def()
				if skipAddrDiff {
					f.Addr = origAddr
				}
				if skipLineDiff {
					f.LineStart = origLineStart
					f.LineEnd = origLineEnd
				}
				if !funcDeclPresent[s] {
					curOverlay.Funcs = append(curOverlay.Funcs, f)
				}
				funcDeclPresent[s] = true
			}
		}
	}

	// Sort variable and function declarations by name.
	overlays := append(dst.Overlays, dst.Overlay)
	for _, overlay := range overlays {
		// Sort variable declarations.
		less := func(i, j int) bool {
			return natsort.Less(overlay.Vars[i].Name, overlay.Vars[j].Name)
		}
		sort.Slice(overlay.Vars, less)
		// Sort function declarations.
		less = func(i, j int) bool {
			return natsort.Less(overlay.Funcs[i].Name, overlay.Funcs[j].Name)
		}
		sort.Slice(overlay.Funcs, less)
	}

	return dst
}

// addUniqueStructs adds unique structs to destination parser.
func addUniqueStructs(dst *csym.Parser, p *csym.Parser, pnum int, fakeCount *int, isPresent *map[string]bool, opts *sym.Options) {
	for tag, structs := range p.StructTags {
		for i := 0; i < len(structs); i++ {
			t := structs[i]
			fake := c.IsFakeTag(t.Tag)
			if fake {
				t.Tag = placeholder
			}
			s := t.Def()
			if fake {
				tag = fmt.Sprintf("struct_fake_%d_%d", pnum, *fakeCount)
				(*fakeCount)++
				t.Tag = tag
			}
			if !(*isPresent)[s] {
				if !fake {
					if _, ok := dst.StructTags[tag]; ok {
						tag = fmt.Sprintf("%s_dup_%d", tag, pnum)
						t.Tag = tag
					}
				}
				dst.StructTags[tag] = append(dst.StructTags[tag], t)
				dst.Structs = append(dst.Structs, t)
			}
			(*isPresent)[s] = true
		}
	}
}

// addUniqueUnions adds unique unions to destination parser.
func addUniqueUnions(dst *csym.Parser, p *csym.Parser, pnum int, fakeCount *int, isPresent *map[string]bool, opts *sym.Options) {
	for tag, unions := range p.UnionTags {
		for i := 0; i < len(unions); i++ {
			t := unions[i]
			fake := c.IsFakeTag(t.Tag)
			if fake {
				t.Tag = placeholder
			}
			s := t.Def()
			if fake {
				tag = fmt.Sprintf("union_fake_%d_%d", pnum, *fakeCount)
				(*fakeCount)++
				t.Tag = tag
			}
			if !(*isPresent)[s] {
				if !fake {
					if _, ok := dst.UnionTags[tag]; ok {
						tag = fmt.Sprintf("%s_dup_%d", tag, pnum)
						t.Tag = tag
					}
				}
				dst.UnionTags[tag] = append(dst.UnionTags[tag], t)
				dst.Unions = append(dst.Unions, t)
			}
			(*isPresent)[s] = true
		}
	}
}

// addUniqueEnums adds unique Enums to destination parser.
func addUniqueEnums(dst *csym.Parser, p *csym.Parser, pnum int, fakeCount *int, isPresent *map[string]bool, opts *sym.Options) {
	for tag, enums := range p.EnumTags {
		for i := 0; i < len(enums); i++ {
			t := enums[i]
			fake := c.IsFakeTag(t.Tag)
			if fake {
				t.Tag = placeholder
			}
			s := t.Def()
			if fake {
				tag = fmt.Sprintf("enum_fake_%d_%d", pnum, *fakeCount)
				(*fakeCount)++
				t.Tag = tag
			}
			if !(*isPresent)[s] {
				if !fake {
					if _, ok := dst.EnumTags[tag]; ok {
						tag = fmt.Sprintf("%s_dup_%d", tag, pnum)
						t.Tag = tag
					}
				}
				dst.EnumTags[tag] = append(dst.EnumTags[tag], t)
				dst.Enums = append(dst.Enums, t)
			}
			(*isPresent)[s] = true
		}
	}
}

// dump dumps the declarations of the parser to the given output directory, in
// the format specified.
func dump(p *csym.Parser, outputDir string, outputC, outputTypes, outputIDA, splitSrc, merge bool) error {

	if outputC {
		// Output C types and declarations.
		if err := initOutputDir(outputDir); err != nil {
			return errors.WithStack(err)
		}
		if err := dumpTypes(p, outputDir); err != nil {
			return errors.WithStack(err)
		}
		if splitSrc {
			if err := dumpSourceFiles(p, outputDir); err != nil {
				return errors.WithStack(err)
			}
		} else {
			if err := dumpDecls(p, outputDir); err != nil {
				return errors.WithStack(err)
			}
		}
	}

	if outputTypes {
		// Output C types.
		if err := initOutputDir(outputDir); err != nil {
			return errors.WithStack(err)
		}
		if err := dumpTypes(p, outputDir); err != nil {
			return errors.WithStack(err)
		}
	}

	if outputIDA {
		// Output IDA scripts.
		if err := initOutputDir(outputDir); err != nil {
			return errors.WithStack(err)
		}
		if err := dumpIDAScripts(p, outputDir); err != nil {
			return errors.WithStack(err)
		}
		// Delete bool and __int64 types as they cause issues with IDA.
		delete(p.Types, "bool")
		for i, def := range p.Typedefs {
			if v, ok := def.(*c.VarDecl); ok {
				if v.Name == "__int64" {
					defs := append(p.Typedefs[:i], p.Typedefs[i+1:]...)
					p.Typedefs = defs
					break
				}
			}
		}
		delete(p.Types, "__int64")
		if err := dumpTypes(p, outputDir); err != nil {
			return errors.WithStack(err)
		}

	}

	return nil
}

// initOutputDir initializes the output directory.
func initOutputDir(outputDir string) error {
	// Only remove output directory if set to default. Otherwise, let user remove
	// output directory as a safety precaution.
	if outputDir == dumpDir {
		if err := os.RemoveAll(outputDir); err != nil {
			return errors.WithStack(err)
		}
	}
	if err := os.MkdirAll(outputDir, 0755); err != nil {
		return errors.WithStack(err)
	}
	return nil
}
