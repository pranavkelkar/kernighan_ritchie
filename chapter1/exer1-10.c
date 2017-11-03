//Exercise 1-10
//Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in unambiguous way.
 
#include<stdio.h>

int main()
{
        char c;
        while((c=getchar())!=EOF)
        {
                // comparing ASCII values
                if(c == 9)//tab
                {
                        putchar(92);//backslash
                        putchar('t');
                }
                //this dosent work as backspace is handled by shell itself
                else if(c == 8)//backspace
                {
                        putchar(92);
                        putchar('b');
                }
                else if(c == 92)//backslash
                {
                        putchar(92);
                        putchar(92);
                }
                else
                        putchar(c);
        }
        return 0;
}
