package csym

import (
	"fmt"

	"github.com/mefistotelis/psx_mnd_sym/csym/c"
)

//TODO make unique names of types
//TODO make unique names of functions
//TODO remove duplicate items

// MakeNamesUnique goes through parsed symbols and renames duplicate ones.
func (p *Parser) MakeNamesUnique() {
	if p.opts.Verbose { fmt.Printf("Making names unique...\n") }
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
			v.Var.Name = UniqueVarName(overlay, v)
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
			f.Var.Name = UniqueFuncName(overlay, f)
		}
	}
}

// UniqueName returns a unique name based on the given name and address.
func UniqueName(name string, addr uint32) string {
	return fmt.Sprintf("%s_addr_%08X", name, addr)
}

// UniqueVarName returns a unique name for a variable declaration
func UniqueVarName(overlay *Overlay, v *c.VarDecl) string {
	return fmt.Sprintf("%s_addr_%08X", v.Var.Name, v.Addr)
}

// UniqueFuncName returns a unique name for a variable declaration
func UniqueFuncName(overlay *Overlay, f *c.FuncDecl) string {
	return fmt.Sprintf("%s_addr_%08X", f.Var.Name, f.Addr)
}
