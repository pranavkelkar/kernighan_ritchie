//Exercise 1-17
//Write a program to print all input lines that are longer than 80 characters.
//Note : Considered for 10 characters for testing.
#include<stdio.h>
#define MAXLINE 100
#define BUFFERLEN 1000
#define MAXLEN 10

//function prototypes
int mygetline(char line[], int maxline);
int copy(char buffer[], char line[], int head);

int main()
{
	int len;
	int head = 0;
	char line[MAXLINE];
	char buffer[BUFFERLEN];
	
	while((len = mygetline(line,MAXLINE)) > 0) //this function returns length considering newline character
	{
		if(len > MAXLEN)//newline character also considered in length			
		{
			head = copy(buffer,line,head);
		}
	}

	buffer[head++] = '\0';
	printf("\nLines longer than 10 chars(including newline) : \n%s\n",buffer);
	return 0;
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

int copy(char buffer[], char line[], int head)
{
	int i,j;
	i=j=0;
	while(line[j++] != '\0')
	{
		buffer[head++] = line[i++];
	}
	return head;
}

//Note : When Ctrl + D is used in middle of line, we have to press 3 times.
//Should work in 2 times, 1 for flush, 1 for EOF

//A line of only spaces / tabs is also considered as valid line input.
