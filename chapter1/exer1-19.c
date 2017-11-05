//Exercise 1-19
//Write a function reverse(s) thar reverses the character string s.
//Use it to write a program that reverses its input a line at a time.

#include<stdio.h>
#define MAXLINE 100


//function prototypes
int mygetline(char line[], int maxline);
void reverse(char rline[], char line[], int len);

int main()
{
	int len;
	char line[MAXLINE];
	char rline[MAXLINE];
	while((len = mygetline(line,MAXLINE)) > 0) //this function returns length considering newline character
	{
		reverse(rline,line,len);
		printf("Reversed : %s",rline);
	}
	return 0;
}

/* reverse : reverses input string */
void reverse(char rline[], char line[], int len)
{
	int last_char,i,j;
	//to retain newline char in rline
	last_char = line[len-1];
	i = len-1;
	j = 0;
	if(last_char == 10)
		--i;
	//reverse line
	while(i>=0)
	{
		rline[j++] = line[i--];
	}
	//retain newline
	if(last_char == 10)
		rline[j++] = 10;
	//add valid statement terminator
	rline[j++] = '\0';
}

/* mygetline : read a line into s, return length */
int mygetline(char s[], int lim)
{
	int i, c;
	
	for(i=0; i<lim-1 && (c = getchar())!= EOF && c!='\n' ;++i )
		s[i] = c;
	if(c=='\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

