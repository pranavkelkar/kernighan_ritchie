Compiling multiple source files
gcc intext1-10_main.c intext1-10_functions.c

Note : If we try to individually compile the files, we get linker error.

What is the mechanism then to compile these files individually and link them at runtime ?

The header files are included in both files, in this case what happens in precompilation phase ?
