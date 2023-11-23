Non-exhaustive list of bugs/inconsistencies found so far:

- when specifying `-c`, `-ida`, `-types`, the file `types.h` is generated as many times
    - there is no point in doing so as they would overwrite each other
        - except for `-c -ida` where one wants `decls.h` from `-c`
    - NOTE: the order these are generated internally is `c, types, ida`
- `-types` alone generates the same content as many times as there are files in .SYM?
    - `-merge` should be implicitly used?
    - NOTE: `types.h` still contains dupe typedefs when using `-c` or `-ida`
- `-dir` must be `-dir=...` but will crash when there are quotes
- `-src` alone does DUMPSYM behavior, it should fail and expect another parameter