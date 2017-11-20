#include<stdio.h>
#include<string.h>
#define MAXLINES 5000 /* max #lines to be sorted */

//global variables
char *lineptr[MAXLINES];

//function prototypes
extern int readlines(char *lineptr[], int nlines);
extern void writelines(char *lineptr[], int nlines);
extern void qsort(char *lineptr[], int left, int right);

//main
int main()
{
	int nlines; // number of input line read
		
	return 0;
}
