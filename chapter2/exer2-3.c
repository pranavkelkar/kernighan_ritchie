//Exercise 2-3
//Write the function htoi(s), which converts a string of hexadecimal digits
//(including on optional 0x or 0X) into its equivalent integer value.
//The allowable digits are 0 through 9, a through f, and A through F.

#include<stdio.h>
#include<ctype.h>

#define MAXLINE 1000
//function prototypes
int mygetline(char s[], int lim);
int my_htoi(char[],int);
int power(int,int);
void reverse(char rline[], char line[], int len);

int main()
{
	char line[MAXLINE];
	int number;
	int size;
	while((size = mygetline(line,MAXLINE)) > 0 )
	{
		printf("Line : %s\n",line);
		printf("Size : %d\n",size);
		number = my_htoi(line,size);
		printf("Number : %d\n",number);
	}
	return 0;
}

/* line should be passed to my_htoi() only after verification that it has valid hex chars.
a separate function should be written for that. */
int my_htoi(char line[],int size)
{
	int i,n;
	int position = 0;
	n = 0;
	char s[MAXLINE];
	reverse(s,line,size);
	printf("Reversed string : %s\n",s);
	for(i=0;s[i]!='\0' && (s[i]>='0' && s[i]<='9') ||  (s[i]>='A' && s[i] <='F');++i)
	{
		if(s[i]>='A' && s[i]<='F')//if A-F convert to 10-15
		{
			s[i] = s[i] -55;//bad to put magic number, change this later
		}
		else
		{
			s[i] = s[i] - 48;
		}
		//printf("s[i]: %d\n",s[i]);
		n = n  +  s[i] * power(16,position);
		//printf("n : %d\n",n);
		position ++;
	}
	return n;
}

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

int power(int base, int n)
{
	int i,p = 1;
	for(i= 1 ; i<=n ; ++i)
		p = p * base;
	return p;

}
/* return line + convert case to upper, this should be added in differnt function later */
int mygetline(char s[], int lim)
{
	int i, c;
	
	for(i=0; i<lim-1  && (c = getchar())!= EOF && c!='\n';++i )
		s[i] = toupper(c);
	if(c=='\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
