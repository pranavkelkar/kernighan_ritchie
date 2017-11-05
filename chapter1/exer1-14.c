//Exercise 1-14
//Write a program to print a histogram of the frequencies of different characters in its input

//Note : In interest of displaying the histogram, character set a-z will be considered.
//ASCII a - 97, z - 122
#include<stdio.h>
#define MAX 26
int main()
{
	int c, i, j;
	int char_array[MAX];

	//initializing count of histogram elements to 0
	for (i=0;i<MAX;i++)
		char_array[i] = 0;

	//count character frequency from input
	while((c = getchar()) != EOF)
	{
		if(c>=97 && c<=122)
		{
			char_array[c-97]++;
		}			
	}

	//print histogram - horizontal bars
	printf("\n------ Histogram ------");
	for (i=0; i<MAX; i++)
	{
		printf("\n[%c]|",i+97);
		for(j=0; j<char_array[i]; j++)
			printf("-"); 
		 		
	}
	printf("\n");	
	
	return 0;
}
