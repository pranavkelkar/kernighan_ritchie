/*
atoi for converting string to its numerical equivalent
this program copes with leading white spaces and optional + or - sign
*/

#include<stdio.h>
#include<ctype.h>
#define MAXLINE 1000

//function prototypes
int mygetline(char [],int);
int atoi(char []);

/* main */
int main()
{
	int size;
	char line[MAXLINE];
	
	while((size = mygetline(line,MAXLINE)) > 0)
	{
		printf("Line : %s",line);
		//convert to int
		printf("atoi : %d\n",atoi(line));		
	}
	return 0;
}

int mygetline(char s[], int lim)
{
	int c, i;
	
	for(i = 0; i < lim-1 && (c = getchar())	!= EOF && c !='\n' ; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}
	
/* atoi: convert s to integer; version 2 */	

int atoi(char s[])
{
	int i, n, sign;
	
	for(i = 0; isspace(s[i]); i++) /* skip white spaces */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-') /* skip sign */
		i++;
	for(n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
