//Exercise 1-13
//Write a program to print histogram of the lenghts of words in its input.
//It is easy to draw the histogram with bars horizontal,
//a vertical orientation is more challenging.

#include<stdio.h>
#define IN 1
#define OUT 0
#define MAX 11
int main()
{
	int nw, state, word_len, c, i, j;
	int word_len_array[MAX];

	state = OUT;
	nw = 0;
	word_len = 0;

	//initializing count of histogram elements to 0
	for (i=0;i<MAX;i++)
		word_len_array[i] = 0;

	//count length of words and store in appropriate position in word_len_array
	while((c = getchar()) != EOF)
	{
		if(c != ' ' && c != '\n' && c != '\t')
		{
			word_len ++;
		}
		
		if(c == ' ' || c == '\n' || c == '\t')
		{
			//printf("Word length : %d\n",word_len);
			if(word_len < MAX) // to avoid accessing elements out of array
				word_len_array[word_len] ++;
			word_len = 0;			
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}

	//print histogram - horizontal bars
	printf("\n------ Histogram ------");
	for (i=1; i<MAX; i++)
	{
		printf("\nlength[%d]\t|",i);
		for(j=0; j<word_len_array[i]; j++)
			printf("-"); 		
	}
	printf("\n");
	return 0;
}

//Note : This program gives wrong results when buffer is flushed with Ctrl-D to obtain histogram(when cursor not at start of line).
//This is because word end condition is only checked with blank, tab and newline.
//This may also cause some bugs in previously written word counting related programs.

//Priting histogram with vertical bars can be done using matrices(matrix rotation). 
//Bit tricky but worth a try! Reserved for later.
//Typically when we rotate images(rotate left by 90 / rotate right by 90),
//we use matrix rotation.
