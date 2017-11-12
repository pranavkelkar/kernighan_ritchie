/* convert stirng to integer */

#include<stdio.h>
#define MAXLINE 1000

//function prototypes
int mygetline(char s[], int lim);
int my_atoi(char[]);

int main()
{
	char line[MAXLINE];
	int number;
	int size;
	while((size = mygetline(line,MAXLINE)) > 0 )
	{
		number = my_atoi(line);
		printf("Number = %d\n",number);
	}	
	return 0;
}

int my_atoi(char s[])
{
	int i,n;
	n = 0;
	for(i=0;s[i]!='\0' && s[i]>='0' && s[i]<='9';++i)
	n = n * 10 + (s[i]-'0');
	return n;
}

int mygetline(char s[], int lim)
{
	int i, c;
	
	for(i=0; i<lim-1  && (c = getchar())!= EOF && c!='\n';++i )
		s[i] = c;
	if(c=='\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
