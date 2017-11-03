//Exercise 1-8
//Write a program to count blanks, tabs and newlines
#include<stdio.h>

int main()
{
        long blank_count = 0, tab_count = 0, newline_count = 0;
        int c;
        while ((c = getchar()) != EOF)
        {
                if(c==' ')
                        ++blank_count;
                if(c=='\t')
                        ++tab_count;
                if(c=='\n')
                        ++newline_count;
        }
        printf("\nblank_count = %ld\ntab_count = %ld\nnewline_count =  %ld\n",blank_count,tab_count,newline_count);
        return 0;
}
