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
	p.makeNamesUniqueInOverlay(p.Overlay)
	// Other overlays
	for _, overlay := range p.Overlays {
		p.makeNamesUniqueInOverlay(overlay)
	}
}

// makeNamesUniqueInOverlay goes through parsed symbols and renames duplicate ones.
func (p *Parser) makeNamesUniqueInOverlay(overlay *Overlay) {
	for _, variables := range overlay.varNames {
		if  len(variables) < 2 { continue }
		for i := 0; i < len(variables); i++ {
			v := variables[i]
			v.Var.Name = uniqueVarName(overlay, v)
		}
	}
}

// uniqueVarName returns a unique name for a variable declaration
func uniqueVarName(overlay *Overlay, v *c.VarDecl) string {
	variables, ok := overlay.varNames[v.Var.Name]
	if ok && len(variables) > 1 {
		return fmt.Sprintf("%s_addr_%08X", v.Var.Name, v.Addr)
	}
	return v.Var.Name
}


