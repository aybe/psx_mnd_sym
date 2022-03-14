package csym

import (
	"fmt"
	"reflect"

	"github.com/mefistotelis/psx_mnd_sym/csym/c"
)

// RemoveDuplicateTypes goes through parsed types and marks exact duplicates.
func (p *Parser) RemoveDuplicateTypes() {
	if p.opts.Verbose { fmt.Printf("Remove duplicate types...\n") }
	p.removeStructsDuplicates()
}

// removeStructsDuplicates goes through parsed symbols and marks exact duplicates.
func (p *Parser) removeStructsDuplicates() {
	n := 0
	for _, structs := range p.StructTags {
		for i := 0; i < len(structs); i++ {
			t1 := structs[i]
			if t1 == nil { continue }
			for k := i+1; k < len(structs); k++ {
				t2 := structs[k]
				if !reflect.DeepEqual(t2, t1) { continue }
				// Replace the pointers with nil, to avoid reordering too often
				p.ReplaceStruct(t2, nil)
				n++
			}
		}
		// Remove nil items
		p.RmNilStructs()
	}
	if p.opts.Verbose { fmt.Printf("Removed structs: %d\n", n) }
}

// MakeNamesUnique goes through parsed symbols and renames duplicate names.
func (p *Parser) MakeNamesUnique() {
	if p.opts.Verbose { fmt.Printf("Making names unique...\n") }
	p.makeStructsUnique()
	p.makeUnionsUnique()
	p.makeEnumsUnique()
	// Default overlay
	p.makeVarNamesUniqueInOverlay(p.Overlay)
	p.makeFuncNamesUniqueInOverlay(p.Overlay)
	// Other overlays
	for _, overlay := range p.Overlays {
		p.makeVarNamesUniqueInOverlay(overlay)
		p.makeFuncNamesUniqueInOverlay(overlay)
	}
}

// makeVarNamesUniqueInOverlay goes through parsed symbols and renames duplicate ones.
func (p *Parser) makeVarNamesUniqueInOverlay(overlay *Overlay) {
	for _, variables := range overlay.varNames {
		// Do not rename extern declarations, only real variables
		real_len := 0
		for i := 0; i < len(variables); i++ {
			v := variables[i]
			if v.Class == c.Extern { continue }
			real_len++
		}
		if  real_len < 2 { continue }
		for i := 0; i < len(variables); i++ {
			v := variables[i]
			if v.Class == c.Extern { continue }
			v.Var.Name = UniqueVarName(overlay.varNames, v)
		}
	}
}

// makeFuncNamesUniqueInOverlay goes through parsed symbols and renames duplicate ones.
func (p *Parser) makeFuncNamesUniqueInOverlay(overlay *Overlay) {
	for _, funcs := range overlay.funcNames {
		// Do not rename extern declarations
		real_len := len(funcs)
		if  real_len < 2 { continue }
		for i := 0; i < len(funcs); i++ {
			f := funcs[i]
			f.Var.Name = UniqueFuncName(overlay.funcNames, f)
		}
	}
}

// makeStructsUnique goes through parsed symbols and renames duplicate ones.
func (p *Parser) makeStructsUnique() {
	for _, structs := range p.StructTags {
		real_len := len(structs)
		if  real_len < 2 { continue }
		for i := 0; i < len(structs); i++ {
			t := structs[i]
			t.Tag = UniqueStructTag(p.StructTags, t)
		}
	}
}

// makeUnionsUnique goes through parsed symbols and renames duplicate ones.
func (p *Parser) makeUnionsUnique() {
	for _, unions := range p.UnionTags {
		real_len := len(unions)
		if  real_len < 2 { continue }
		for i := 0; i < len(unions); i++ {
			t := unions[i]
			t.Tag = UniqueUnionTag(p.UnionTags, t)
		}
	}
}

// makeEnumsUnique goes through parsed symbols and renames duplicate ones.
func (p *Parser) makeEnumsUnique() {
	for _, enums := range p.EnumTags {
		real_len := len(enums)
		if  real_len < 2 { continue }
		for i := 0; i < len(enums); i++ {
			t := enums[i]
			t.Tag = UniqueEnumTag(p.EnumTags, t)
		}
	}
}

// UniqueName returns a unique name based on the given name and address.
func UniqueName(name string, addr uint32) string {
	return fmt.Sprintf("%s_addr_%08X", name, addr)
}

// UniqueTag returns a unique tag based on the given tag and duplicate index.
func UniqueTag(tag string, idx int) string {
	return fmt.Sprintf("%s_duplicate_%d", tag, idx)
}

// UniqueVarName returns a unique variable name based on the given variable
// and set of present variables mapped by names.
func UniqueVarName(varNames map[string][]*c.VarDecl, v *c.VarDecl) string {
	newName := v.Var.Name
	newName = UniqueName(newName, v.Addr)
	return newName
}

// UniqueFuncName returns a unique function name based on the given function
// and set of present functions mapped by names.
func UniqueFuncName(funcNames map[string][]*c.FuncDecl, f *c.FuncDecl) string {
	newName := f.Var.Name
	newName = UniqueName(newName, f.Addr)
	return newName
}

// UniqueStructTag returns a unique struct tag based on the given struct
// and set of present structs mapped by tags.
func UniqueStructTag(structTags map[string][]*c.StructType, t *c.StructType) string {
	newTag := t.Tag
	for {
		structs, ok := structTags[newTag]
		if !ok { break } // the tag is unique - done
		k := SliceIndex(len(structs), func(i int) bool { return structs[i] == t })
		if k < 0 { k = len(structs) }
		newTag = UniqueTag(newTag, k)
	}
	return newTag
}

// UniqueUnionTag returns a unique union tag based on the given union
// and set of present unions mapped by tags.
func UniqueUnionTag(unionTags map[string][]*c.UnionType, t *c.UnionType) string {
	newTag := t.Tag
	for {
		unions, ok := unionTags[newTag]
		if !ok { break } // the tag is unique - done
		k := SliceIndex(len(unions), func(i int) bool { return unions[i] == t })
		if k < 0 { k = len(unions) }
		newTag = UniqueTag(newTag, k)
	}
	return newTag
}

// UniqueEnumTag returns a unique enum tag based on the given enum
// and set of present enums mapped by tags.
func UniqueEnumTag(EnumTags map[string][]*c.EnumType, t *c.EnumType) string {
	newTag := t.Tag
	for {
		enums, ok := EnumTags[newTag]
		if !ok { break } // the tag is unique - done
		k := SliceIndex(len(enums), func(i int) bool { return enums[i] == t })
		if k < 0 { k = len(enums) }
		newTag = UniqueTag(newTag, k)
	}
	return newTag
}

