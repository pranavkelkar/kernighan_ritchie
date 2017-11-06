//Program to demonstrate externa variables and scope.
//Refer pg 32

#include<stdio.h>

#define MAXLINE 1000 	/* maximum input line size */

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


/* mygetline : specialized version */
int mygetline(void)
{
	int c, i;
	//extern char line[];
	//If definition of an external variable occurs in the source file
	//before its use in a particular funtion, then there is no need for
	//an external declaration in the function.

	for(i=0; i< MAXLINE-1 && (c = getchar())!=EOF && c!='\n' ; ++i)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = c;
		++i;
	}
	
	line[i] = '\0';
	return i;
}

/* copy : specialized version */
void copy(void)
{
	int i;
	//extern char line[], longest[];
	//If definition of an external variable occurs in the source file
	//before its use in a particular funtion, then there is no need for
	//an external declaration in the function.

	i= 0;
	while((longest[i] = line[i]) != '\0')
		++i;
}


