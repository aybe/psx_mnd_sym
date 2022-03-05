# sym

[![Build Status](https://api.travis-ci.com/mefistotelis/psx_mnd_sym.svg)](https://app.travis-ci.com/github/mefistotelis/psx_mnd_sym)
[![GoDoc](https://godoc.org/github.com/mefistotelis/psx_mnd_sym?status.svg)](https://godoc.org/github.com/mefistotelis/psx_mnd_sym)

Parse Playstation 1 symbol files (`*.SYM`).

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
