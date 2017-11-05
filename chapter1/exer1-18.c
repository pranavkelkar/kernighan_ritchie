//Execersie 1-18
//Write a program to remove trailing blanks and tabs from each line input,
//and to delete entirely blank lines.

#include<stdio.h>
#define MAXLINE 100
#define EMPTY 0
#define NOTEMPTY 1
#define BUFFERLEN 1000

//function prototypes
int mygetline(char line[],int maxline);
int copy(char buffer[], char line[], int head);
int cleanTrailers(char line[],int length);
int main()
{
	int len;
	int head = 0;
	char line[MAXLINE];
	char buffer[BUFFERLEN];
	int result;
	while((len = mygetline(line,MAXLINE)) > 0) //this function returns length considering newline character
	{
			result = cleanTrailers(line,len);
			if(result !=EMPTY)
				head = copy(buffer,line,head);
			//else ignore
	}

	buffer[head++] = '\0';
	printf("\nAfter removing trailing tabs and spaces : \n%s\n",buffer);
	return 0;
}

/* cleanTrailers: clean trailing spaces, tabs and empty lines */
int cleanTrailers(char s[], int len)
{
	int i, last_char;
	//start from rear and replace each blank and tab by '\0'
	last_char = s[len-1];
	for(i=len-1;i>=0;i--)
	{
		//most significant characters are present after 32 in ASCII table, not full proof, but works
		if(s[i] > 32)
		break;
		//if last character is newline char(ASCII 10) then remove tabs, spaces between newline and significant chars
		if(last_char == 10  && s[i]=='\t' || s[i]==' ')
		{
			s[i]='\n';
			s[i+1]='\0';
		}
		//else remove spaces and tabs
		else if(s[i]=='\t' || s[i]==' ')
			s[i]='\0';
	}
	//if first character itself is '\0' or newline, it means line is empty
	if(s[0]=='\0' || s[0]==10)
		return EMPTY;
	else
		return NOTEMPTY;
}

/* mygetline : read a line into s, return length */
int mygetline(char s[],int lim)
{
	int i, c;
	for(i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n' ; ++i)
		s[i] = c;
	if(c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy line to buffer */
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
