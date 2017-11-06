//Program to demonstrate externa variables and scope.
//Refer pg 32

#include<stdio.h>
#include"intext1-10_header.h"
int max;				/* maximum length seen so far */
char line[MAXLINE];		/* current input line */
char longest[MAXLINE];	/* longest line saved here */

//function prototypes
int mygetline(void);
void copy(void);

/* print longest input line: specialized version */
int main()
{
	int len;
	extern int max;
	//extern char longest[];
	//If definition of an external variable occurs in the source file
	//before its use in a particular funtion, then there is no need for
	//an external declaration in the function.

	max = 0;
	while ((len = mygetline()) > 0)
	{
		if(len > max)
		{
			max = len;
			copy();
		}
	}
	if(max > 0)				/* there was a line*/
		printf("Longest line : %s\n",longest);
	return 0;	
}





