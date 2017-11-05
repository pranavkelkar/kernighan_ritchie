//Exercise 1-16
//Revise the main routine of the longest-line program so it will correctly
//print the length of arbitrarily long input lines, and as much as possible
//of the text.

//Note : This program already holds capacity to find and print arbitrarily long input lines.
//PROBLEM STATEMENT NOT CLEAR

#include<stdio.h>
#define MAXLINE 1000

int mygetline(char line[],int maxline);
void copy(char to[], char from[]);

/* print longest input line */

int main()
{
	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */	
	
	max = 0;

	while((len = mygetline(line,MAXLINE)) > 0)
	{
		if(len > max)
		{
			max = len;
			copy(longest,line);
		}
	}

	if(max > 0) /* there was a line */
		printf("Longest : %s",longest);
	return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
	int c, i;

	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if(c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy : copy 'from' into 'to' ; assume to is big enough */
void copy(char to[],char  from[])
{
	int i;
	
	i = 0;
	while((to[i] = from[i]) != '\0')
	{
		++i;
	}
}	


//Note : Here variable names in function declaration and function definition are different,
//but their data types must be the same, else it would be compile time error.

//Also, function name "getline" is standard library function hence will not compile.
//Hence, changed function name to "mygetline".
