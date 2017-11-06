gcc hello.c > a.out - which is an executable
try these switches
-o to name the executable file produced ( by default it is a.out )
-Wall to enable all warnings
-std=c99 to comply with the standard
e.g gcc -o hello_world -Wall -std=c99 hello_world.c

The basic programs that gcc makes use of while compiling a C program are :-
cpp	GNU C pre-processor
cc	GNU C compiler
as 	assembler
ld	linker

All these programs are present on a Linux machine(as a proof) :-
gcc_compiler_demo $ which cpp
/usr/bin/cpp
gcc_compiler_demo $ which cc
/usr/bin/cc
gcc_compiler_demo $ which as
/usr/bin/as
gcc_compiler_demo $ which ld
/usr/bin/ld

Flow chart of C program compilation :-

		hello_world.c
		     |
		   cpp- the C pre-processor
		     |
		hello_world.i -input file to the C compiler
		     |
		    cc
		     |
		hello_world.s -input file to the assembler
		     |
		    as
		     |
		hello_world.o - input file to the linker
		     |
		    ld
		     |
		 hello_world


hello_world.c
#include<stdio.h>

int main()
{
	printf("Hello World\n");
	return 0;
}

E.g of program
Try 1 :
gcc_compiler_demo $ ls
hello_world.c  readme.txt
gcc_compiler_demo $ cpp hello_world.c > hello_world.i
gcc_compiler_demo $ ls
hello_world.c  hello_world.i  readme.txt
gcc_compiler_demo $ cc -S hello_world.i
gcc_compiler_demo $ ls
hello_world.c  hello_world.i  hello_world.s  readme.txt
gcc_compiler_demo $ as -o hello_world.o hello_world.s
gcc_compiler_demo $ ls
hello_world.c  hello_world.i  hello_world.o  hello_world.s  readme.txt
gcc_compiler_demo $ ld --dynamic-linker /lib32/ld-linux.so.2 /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o hello_world.o -lc -o hello_world
gcc_compiler_demo $ ls
hello_world  hello_world.c  hello_world.i  hello_world.o  hello_world.s  readme.txt
gcc_compiler_demo $ ./hello_world 
bash: ./hello_world: Accessing a corrupted shared library
gcc_compiler_demo $

----in this approach I am using a 32 bit file /lib32/ld-linux.so.2 - hence its failing



Try 2 :
gcc_compiler_demo $ ls
hello_world.c  readme.txt
gcc_compiler_demo $ cpp hello_world.c > hello_world.i
gcc_compiler_demo $ ls
hello_world.c  hello_world.i  readme.txt
gcc_compiler_demo $ cc -S hello_world.i
gcc_compiler_demo $ ls
hello_world.c  hello_world.i  hello_world.s  readme.txt
gcc_compiler_demo $ as -o hello_world.o hello_world.s
gcc_compiler_demo $ ls
hello_world.c  hello_world.i  hello_world.o  hello_world.s  readme.txt
gcc_compiler_demo $ ld --dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o hello_world.o -lc -o hello_world
gcc_compiler_demo $ ls
hello_world  hello_world.c  hello_world.i  hello_world.o  hello_world.s  readme.txt
gcc_compiler_demo $ ./hello_world 
Hello World
---------now correctly used 64 bit file



Try 3 :
Now defining starting point of program to main instead of _start
gcc_compiler_demo $ ld --dynamic-linker /lib64/ld-linux-x86-64.so.2 -e main hello_world.o -lc -o hello_world
gcc_compiler_demo $ ./hello_world 
Hello World
Segmentation fault
gcc_compiler_demo $ 

---- this is because the process is not able to exit.



Try 4 :
Change program to :-

#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("Hello World\n");
	//return 0;
	exit(0);
}

Now program works perfectly.

Also try this(rename main function to mymain)
#include<stdio.h>
#include<stdlib.h>
int mymain()
{
	printf("Hello World\n");
	//return 0;
	exit(0);
}

change -e(entry point flag) accordingly

ld --dynamic-linker /lib64/ld-linux-x86-64.so.2 -e mymain hello_world.o -lc -o hello_world


