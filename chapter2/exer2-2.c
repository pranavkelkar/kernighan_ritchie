//Exercise 2-2
//Write a loop equivalent to the for loop above without using && or ||.
//(consider for loop of mygetline() function)

#include<stdio.h>
#define MAXLINE 1000

//function prototypes
int mygetline(char s[], int lim);

int main()
{
	char line[MAXLINE];
	int size;
	while((size = mygetline(line,MAXLINE)) > 0 )
		printf("%s",line);
	return 0;
}

int mygetline(char s[], int lim)
{
	int i, c;
	
	for(i=0; ((i<lim-1) + ((c = getchar())!= EOF) + (c!='\n')) == 3 ;++i )
		s[i] = c;
	if(c=='\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
