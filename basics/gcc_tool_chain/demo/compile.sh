#precompiler
cpp hello_world.c > hello_world.i
#compiler
cc -S hello_world.i
#assembler
as -o hello_world.o hello_world.s
#linker _start
#ld --dynamic-linker /lib64/ld-linux-x86-64.so.2 hello_world.o -lc -o hello_world

#linker main(your custom main function)
ld --dynamic-linker /lib64/ld-linux-x86-64.so.2 -e main hello_world.o -lc -o hello_world
