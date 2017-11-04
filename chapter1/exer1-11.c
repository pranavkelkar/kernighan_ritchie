//Exercise 1-11
//How would you test the word count program? What kinds of input are most
//likely to uncover bugs if any?

#include<stdio.h>
#define IN 1
#define OUT 0

int main()
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("\nline_count = %d\nword_count = %d\ncharacter_count = %d\n",nl,nw,nc);
	
	return 0;
}		

//Notes-
//The program should be tested by running it on a set of input lines having 
//varying combinations of words, tabs, spaces and newlines.

//** Expressions connected by && or || are evaluated from left to right, 
//and it is guranreed that evaluation will stop as soon as truth of falsehood is know. 
//This may affect program logic.(doesnt affect logic of this program)
