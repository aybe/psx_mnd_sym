package main

import (
	"fmt"
	"io"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"github.com/mefistotelis/psx_mnd_sym/csym"
	"github.com/mefistotelis/psx_mnd_sym/csym/c"
	"github.com/pkg/errors"
	"github.com/rickypai/natsort"
)

// --- [ Type definitions ] ----------------------------------------------------

// Type definitions header file name.
const typesName = "types.h"

// dumpTypes outputs the type information recorded by the parser to a C header
// stored in the output directory.
func dumpTypes(p *csym.Parser, outputDir string) error {
	// Create output file.
	typesPath := filepath.Join(outputDir, typesName)
	fmt.Println("creating:", typesPath)
	f, err := os.Create(typesPath)
	if err != nil {
		return errors.WithStack(err)
	}
	defer f.Close()
	// Print predeclared identifiers.
	if def, ok := p.Types["bool"]; ok {
		if _, err := fmt.Fprintf(f, "%s;\n\n", def.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	// Print enums.
	for _, t := range p.Enums {
		if _, err := fmt.Fprintf(f, "%s;\n\n", t.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	// Print structs.
	for _, t := range p.Structs {
		if _, err := fmt.Fprintf(f, "%s;\n\n", t.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	// Print unions.
	for _, t := range p.Unions {
		if _, err := fmt.Fprintf(f, "%s;\n\n", t.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	// Print typedefs.
	for _, def := range p.Typedefs {
		if _, err := fmt.Fprintf(f, "%s;\n\n", def.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	return nil
}

// --- [ Global declarations ] -------------------------------------------------

const (
	// Declarations header file name.
	declsName = "decls.h"
	// Overlay header file name format string.
	overlayNameFormat = "overlay_%x.h"
)

// dumpDecls outputs the declarations recorded by the parser to C headers stored
// in the output directory.
func dumpDecls(p *csym.Parser, outputDir string) error {
	// Create output file.
	declsPath := filepath.Join(outputDir, declsName)
	fmt.Println("creating:", declsPath)
	f, err := os.Create(declsPath)
	if err != nil {
		return errors.Wrapf(err, "unable to create declarations header %q", declsPath)
	}
	defer f.Close()
	// Store declarations of default binary.
	if err := dumpOverlay(f, p.Overlay); err != nil {
		return errors.WithStack(err)
	}
	// Store declarations of overlays.
	for _, overlay := range p.Overlays {
		overlayName := fmt.Sprintf(overlayNameFormat, overlay.ID)
		overlayPath := filepath.Join(outputDir, overlayName)
		fmt.Println("creating:", overlayPath)
		f, err := os.Create(overlayPath)
		if err != nil {
			return errors.Wrapf(err, "unable to create overlay header %q", overlayPath)
		}
		defer f.Close()
		if err := dumpOverlay(f, overlay); err != nil {
			return errors.WithStack(err)
		}
	}
	return nil
}

// dumpOverlay outputs the declarations of the overlay, writing to w.
func dumpOverlay(w io.Writer, overlay *csym.Overlay) error {
	// Add types.h include directory.
	if _, err := fmt.Fprintf(w, "#include %q\n\n", typesName); err != nil {
		return errors.WithStack(err)
	}
	if overlay.Addr != 0 || overlay.ID != 0 || overlay.Length != 0 {
		if _, err := fmt.Fprintf(w, "// === [ Overlay ID %x ] ===\n\n", overlay.ID); err != nil {
			return errors.WithStack(err)
		}
	}

	// Print variable declarations.
	fmt.Fprintln(w, "// [PSX-MND-SYM] Variables (begin)")
	fmt.Fprintln(w)
	for _, v := range overlay.Vars {
		if _, err := fmt.Fprintf(w, "%s;\n\n", v.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	fmt.Fprintln(w, "// [PSX-MND-SYM] Variables (end)")

	fmt.Fprintln(w)

	// Print function declarations.
	fmt.Fprintln(w, "// [PSX-MND-SYM] Functions (begin)")
	fmt.Fprintln(w)
	for _, f := range overlay.Funcs {
		if _, err := fmt.Fprintf(w, "%s\n\n", f.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	fmt.Fprintln(w, "// [PSX-MND-SYM] Functions (end)")

	return nil
}

// --- [ Source files ] --------------------------------------------------------

// A SourceFile is a source file.
type SourceFile struct {
	// Source file path.
	Path string
	// Variable declarations.
	vars []*c.VarDecl
	// Function declarations.
	funcs []*c.FuncDecl
}

// dumpSourceFiles outputs the source files recorded by the parser to the output
// directory.
func dumpSourceFiles(p *csym.Parser, outputDir string) error {
	srcs := getSourceFiles(p)
	for _, src := range srcs {
		// Create source file directory.
		path := strings.ToLower(src.Path)
		path = strings.Replace(path, `\`, "/", -1)
		if strings.HasPrefix(path[1:], ":/") {
			path = path[len("c:/"):]
		}
		path = filepath.Join(outputDir, path)
		dir := filepath.Dir(path)
		if err := os.MkdirAll(dir, 0755); err != nil {
			return errors.WithStack(err)
		}
		fmt.Println("creating:", path)
		f, err := os.Create(path)
		if err != nil {
			return errors.WithStack(err)
		}
		defer f.Close()
		if err := dumpSourceFile(f, src); err != nil {
			return errors.WithStack(err)
		}
	}
	return nil
}

// dumpSourceFile outputs the declarations of the source file, writing to w.
func dumpSourceFile(w io.Writer, src *SourceFile) error {
	if _, err := fmt.Fprintf(w, "// %s\n\n", src.Path); err != nil {
		return errors.WithStack(err)
	}
	// Add types.h include directory.
	if _, err := fmt.Fprintf(w, "#include %q\n\n", typesName); err != nil {
		return errors.WithStack(err)
	}
	// Handle duplicate identifiers.
	names := make(map[string]bool)
	for _, v := range src.vars {
		if names[v.Name] {
			v.Name = csym.UniqueName(v.Name, v.Addr)
		}
		names[v.Name] = true
	}
	for _, f := range src.funcs {
		if names[f.Name] {
			f.Name = csym.UniqueName(f.Name, f.Addr)
		}
		names[f.Name] = true
	}
	// Print variable declarations.
	for _, v := range src.vars {
		if _, err := fmt.Fprintf(w, "%s;\n\n", v.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	// Print function declarations.
	for _, f := range src.funcs {
		if _, err := fmt.Fprintf(w, "%s\n\n", f.Def()); err != nil {
			return errors.WithStack(err)
		}
	}
	return nil
}

// --- [ IDA scripts ] ---------------------------------------------------------

// dumpIDAScripts outputs the declarations recorded by the parser to IDA scripts
// stored in the output directory.
func dumpIDAScripts(p *csym.Parser, outputDir string) error {
	// Create scripts for declarations of default binary.
	if err := dumpIDAOverlay(p.Overlay, outputDir); err != nil {
		return errors.WithStack(err)
	}
	// Create scripts for declarations of overlays.
	for _, overlay := range p.Overlays {
		if err := dumpIDAOverlay(overlay, outputDir); err != nil {
			return errors.WithStack(err)
		}
	}
	return nil
}

// dumpIDAOverlay outputs the declarations of the overlay to IDA scripts.
func dumpIDAOverlay(overlay *csym.Overlay, outputDir string) error {
	// Create scripts for mapping addresses to identifiers.
	dir := outputDir
	if overlay.ID != 0 {
		overlayDir := fmt.Sprintf("overlay_%x", overlay.ID)
		dir = filepath.Join(outputDir, overlayDir)
		if err := os.MkdirAll(dir, 0755); err != nil {
			return errors.WithStack(err)
		}
	}

	writeIdaScript(overlay, dir, "make_psx.py",
		writeIdaPreamble,
		writeIdaVariablesSignatures,
		writeIdaVariablesNames,
		writeIdaFunctionsSignatures,
		writeIdaFunctionsNames,
		writeIdaPostamble)

	return nil
}

type WriteIdaScriptHandler func(overlay *csym.Overlay, w *os.File) error

func writeIdaScript(overlay *csym.Overlay, directory, fileName string, handlers ...WriteIdaScriptHandler) error {

	path := filepath.Join(directory, fileName)

	fmt.Println("creating:", path)

	w, err := os.Create(path)

	if err != nil {
		return errors.Wrapf(err, "unable to create IDA script %q", path)
	}

	defer w.Close()

	for _, handler := range handlers {
		if err := handler(overlay, w); err != nil {
			return errors.WithStack(err)
		}
	}

	return nil
}

func writeIdaPreamble(overlay *csym.Overlay, w *os.File) error {

	fmt.Fprintln(w, `print("PSX: [Executing IDA script] started.")`)
	fmt.Fprintln(w)

	return nil
}

func writeIdaPostamble(overlay *csym.Overlay, w *os.File) error {

	fmt.Fprintln(w)
	fmt.Fprintln(w, `print("PSX: [Executing IDA script] complete.")`)

	return nil
}

func writeIdaFunctionsNames(overlay *csym.Overlay, w *os.File) error {

	fmt.Fprintln(w, `print("PSX: [Assigning functions names] started.")`)
	fmt.Fprintln(w)

	for _, f := range overlay.Funcs {
		if _, err := fmt.Fprintf(w, "set_name(0x%08X, %q, SN_NOWARN)\n", f.Addr, f.Name); err != nil {
			return errors.WithStack(err)
		}
		commentHeader := "[PSX-MND-SYM]"

		comments := []string{
			fmt.Sprintf("%s Function name = %s", commentHeader, f.Name),
			fmt.Sprintf("%s Function signature = %s", commentHeader, f.Type),
			fmt.Sprintf("%s Function address = %X", commentHeader, f.Addr),
			fmt.Sprintf("%s Function file = %s", commentHeader, f.Path),
			fmt.Sprintf("%s Function size = %X", commentHeader, f.Size),
			fmt.Sprintf("%s Function line start = %d", commentHeader, f.LineStart),
			fmt.Sprintf("%s Function line end = %d", commentHeader, f.LineEnd),
			fmt.Sprintf("%s Function line count = %d", commentHeader, f.LineEnd-f.LineStart),
		}

		comment := strings.Join(comments, "\n")

		if _, err := fmt.Fprintf(w, "set_func_cmt(0x%08X, %q, 0)\n", f.Addr, comment); err != nil {
			return errors.WithStack(err)
		}

		fmt.Fprintln(w)
	}

	fmt.Fprintln(w, `print("PSX: [Assigning functions names] complete.")`)

	return nil
}

func writeIdaVariablesNames(overlay *csym.Overlay, w *os.File) error {

	fmt.Fprintln(w, `print("PSX: [Assigning variables names] started.")`)
	fmt.Fprintln(w)

	for _, v := range overlay.Vars {
		if _, err := fmt.Fprintf(w, "set_name(0x%08X, %q, SN_NOWARN)\n", v.Addr, v.Name); err != nil {
			return errors.WithStack(err)
		}
	}

	fmt.Fprintln(w)
	fmt.Fprintln(w, `print("PSX: [Assigning variables names] complete.")`)

	return nil
}

func writeIdaFunctionsSignatures(overlay *csym.Overlay, w *os.File) error {

	fmt.Fprintln(w, `print("PSX: [Assigning functions signatures] started.")`)
	fmt.Fprintln(w)

	for _, f := range overlay.Funcs {
		if _, err := fmt.Fprintf(w, "del_items(0x%08X)\n", f.Addr); err != nil {
			return errors.WithStack(err)
		}
		if _, err := fmt.Fprintf(w, "SetType(0x%08X, %q)\n", f.Addr, f.Var); err != nil {
			return errors.WithStack(err)
		}

		fmt.Fprintln(w)
	}

	fmt.Fprintln(w, `print("PSX: [Assigning functions signatures] complete.")`)

	return nil
}

func writeIdaVariablesSignatures(overlay *csym.Overlay, w *os.File) error {

	fmt.Fprintln(w, `print("PSX: [Assigning variables types] started.")`)
	fmt.Fprintln(w)

	for _, v := range overlay.Vars {
		if _, err := fmt.Fprintf(w, "del_items(0x%08X)\n", v.Addr); err != nil {
			return errors.WithStack(err)
		}
		if _, err := fmt.Fprintf(w, "SetType(0x%08X, %q)\n", v.Addr, v.Var); err != nil {
			return errors.WithStack(err)
		}

		fmt.Fprintln(w)
	}

	fmt.Fprintln(w, `print("PSX: [Assigning variables types] complete.")`)

	return nil
}

// ### [ Helper functions ] ####################################################

// getSourceFiles returns the source files recorded by the parser.
func getSourceFiles(p *csym.Parser) []*SourceFile {
	// Record source file information from overlays.
	overlays := append(p.Overlays, p.Overlay)
	// sources maps from source path to source file.
	sources := make(map[string]*SourceFile)
	for _, overlay := range overlays {
		for _, v := range overlay.Vars {
			srcPath := fmt.Sprintf("global_%x.cpp", overlay.ID)
			src, ok := sources[srcPath]
			if !ok {
				src = &SourceFile{
					Path: srcPath,
				}
				sources[srcPath] = src
			}
			src.vars = append(src.vars, v)
		}
		for _, f := range overlay.Funcs {
			srcPath := f.Path
			src, ok := sources[srcPath]
			if !ok {
				src = &SourceFile{
					Path: srcPath,
				}
				sources[srcPath] = src
			}
			src.funcs = append(src.funcs, f)
		}
	}
	var srcs []*SourceFile
	for _, src := range sources {
		srcs = append(srcs, src)
	}
	less := func(i, j int) bool {
		return natsort.Less(srcs[i].Path, srcs[j].Path)
	}
	sort.Slice(srcs, less)
	return srcs
}
