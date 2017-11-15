#include<stdio.h>
#include<time.h>

#include "array2.h"
#define MAX 10000

//function declarations
void display();
void printline();
void insertion_sort();

int main()
{

	insertion_sort();

	return 0;
}

//function definitions

void insertion_sort()
{	
	int i;
	int element_to_be_inserted;
	int hole_position;
	for(i=1;i<MAX;i++)
	{
		element_to_be_inserted = array[i];
		hole_position = i;
		while(hole_position > 0 && array[hole_position-1] > element_to_be_inserted)
		{
			array[hole_position] = array[hole_position-1];
			hole_position = hole_position -1 ;
		}
		if(hole_position != i)
		{
			array[hole_position] = element_to_be_inserted;
		}
		printf("\nIteration #%d : ",i);
		display();
	}
}

void display()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		printf("\t%d",array[i]);
	}
	printf("\n");
}


