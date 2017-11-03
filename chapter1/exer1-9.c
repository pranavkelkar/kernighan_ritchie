//Exercise 1-9
//Write a program to copy its input to its output, replacing each string with one or more blanks with a single blank.

#include<stdio.h>
#define PRESENT 1
#define ABSENT 0

int main()
{
        int c;
        int blank = ABSENT;
        while((c = getchar()) != EOF)
        {
                if(c ==' ' && blank == ABSENT)
                {
                        blank = PRESENT;
                        putchar(c);
                }
                else if(c != ' ')
                {
                        blank = ABSENT;
                        putchar(c);
                }
        }
        return 0;
}

