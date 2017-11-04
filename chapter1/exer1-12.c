//Exercise 1-12
//Write a program that prints its input one word per line.

#include<stdio.h>
#define IN 1
#define OUT 0

int main()
{	
	int state, c, char_count;
	state = OUT;
	char_count = 0;
	while((c = getchar()) != EOF)
	{
		//to ignore spaces and tabs at start of line
		if(c!=' ' && c!= '\t')
			char_count ++;
		//initialize char_count to 0 for each new line
		if(c == '\n')
			char_count = 0;
		//to check word end
		if(c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		//out of a word and occurence of characters other than ' ', '\t', '\n'
		else if (state == OUT)
		{
			state = IN;
			//put each new word on new line, additonal check to ignore spaces and tabs at start of line
			//this check is essential because we set state = OUT while starting program
			if(char_count!=1)
				putchar('\n');
		}
	 	//if inside word or for a new line, print it			
		if(state == IN || c=='\n')
			putchar(c);
	}
	
	return 0;
}
