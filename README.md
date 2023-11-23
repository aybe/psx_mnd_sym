This fork has the following changes:

- handle `float` and `double` types found in some games
- removal of duplicate typedefs
- consolidated and improved output for IDA
    - output sentinel comments for external parsers
- general improvements (DRY/inconsistencies)

The goal is to generate better sources out of this project's.

Preliminary instructions for IDA:

(read original README first!)

- generate the output files with `sym_dump -c -ida YOUR_FILE.SYM`
- start on a fresh IDB
- set compiler to GNU C++
- add memory mappings (from, to, size) (https://www.romhacking.net/utilities/1165/)
    - 0×00000000, 0×80000000, 0×00200000
    - 0xA0000000, 0×80000000, 0×00200000
- set segments permissions to R/W/X (avoid inlining/MEMORY access)

# PSX MND/SYM parser in Golang

[![Build Status](https://api.travis-ci.com/mefistotelis/psx_mnd_sym.svg)](https://app.travis-ci.com/github/mefistotelis/psx_mnd_sym)
[![GoDoc](https://godoc.org/github.com/mefistotelis/psx_mnd_sym?status.svg)](https://godoc.org/github.com/mefistotelis/psx_mnd_sym)

Parse Playstation 1 symbol files (`*.SYM` files with `MND\1` header).

## Installation

```bash
go get -u github.com/mefistotelis/psx_mnd_sym/cmd/sym_dump
```

## Usage

The default output of `sym_dump` is in Psy-Q format and is identical to the
`DUMPSYM.EXE` tool of the [Psy-Q SDK](http://www.psxdev.net/help/psyq_install.html).

```bash
sym_dump DIABPSX.SYM
# Output:
#
# Header : MND version 1
# Target unit 0
# 000008: $800b031c overlay length $000009e4 id $4
# 000015: $800b031c overlay length $00000004 id $5
# 000022: $80139bf8 overlay length $00023234 id $b
# 00002f: $80139bf8 overlay length $00029dcc id $c
# 00003c: $80139bf8 overlay length $0002a228 id $d
# 000049: $80139bf8 overlay length $0001ec70 id $e
# 000056: $00000000 94 Def class TPDEF type UCHAR size 0 name u_char
```

The tool can also dump C headers with type definitions, variable and function declarations.

```bash
sym_dump -c DIABPSX.SYM
```

IDA Python scripts can be created as well.

```bash
sym_dump -ida DIABPSX.SYM
```

More options can be discovered by triggering help screen.

```bash
sym_dump --help
```

## Preparing IDA Pro project

One of the most prominent features of this tool is the support for IDA Pro
scripts. Here is a tutorial on how to get IDA project with all the debug
data loaded.

#### 1. Open the PSX executable

Open the `SL*` binary in IDA Pro. Since IDA knows the format, it should
propose the correct MIPS processor:
* MIPS little endian, for Playstation 1
* MIPS R5900 little endian, for Playstation 2

If there are multiple binary overlays used by your application, you should use
`File` -> `Load file` -> `Another binary file` to load the `.BIN` files
as well. Unless you want to have a separate IDA project for each overlay,
that's fine as well.

#### 2. Setup the compiler

IDA has no special entry for the Sony SDK compiler; in `Options` -> `Compiler...`,
you can select either _Visual C++_ or _GNU C++_, as the important values
are identical in these two.

#### 3. Load type definitions

Now that IDA knows sizes of basic types and alignment from compiler options,
you can load the header file with type definitions. Use `File` -> `Load file`
-> `Parse C header file...`.

Often the generated `types.h` will have some ordering issues - you can edit it by
hand, reordering structs and unions until IDA is happy to load all the types.

#### 4. Load symbol names and types

Now as types are loaded, you can ask IDA to execute the Python scripts. Use
`File` -> `Script file...`. The order you load them should not matter. There
are 3 files to load:

* `make_psx.py` sets names of all known symbols
* `set_funcs.py` sets function signatures
* `set_vars.py` sets types of global variables

#### 5. Start your analysis

After you load all the files, you are ready to start analyzing the code. If
some functions or globals are not named correctly at this point, they were
probably not included in the `.SYM` file (ie. precompiled libraries compiled
into your executable). But you may compare the addresses with `SYMDUMP.EXE`
output to make sure - that output contains everything the `.SYM` file had,
in the same order, without much interpretation.
