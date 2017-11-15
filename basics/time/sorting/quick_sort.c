#include<stdio.h>
#include<time.h>

#include "array2.h"
#define MAX 10000

//#define MAX 5
//int a[5] = {2,4,3,5,6};

//function prototypes
void display(int [],int);
void quicksort(int[],int,int);
int partition(int[], int, int);


int main()
{
	int n = MAX;
	printf("\n---Quick Sort---\n");
	//display(a,n); //working
	quicksort(a,0,n-1);
	//printf("\nAfter sorting : ");
	//display(a,n);
	printf("\nTime : %ld\n",clock());
	return 0;
}

void quicksort(int a[],int low, int high)
{
	int pivot;
	if(high>low)
	{

		pivot = partition(a,low,high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);

	}
}

int partition(int a[],int low, int high)
{
	int left, right, pivot, temp;
	pivot = a[low];
	left = low;
	right = high;
	while(left < right)
	{
		while(a[left] <= pivot && left <= high)
			left ++;
		while(a[right] > pivot && right >= low)
			right --;
		if(left < right)
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}

	}

	a[low] = a[right];
	a[right] = pivot;
	return right;
}

void display(int a[],int n)
{
	int i;
	printf("\nElements of array are : ");
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
	printf("\n");
}
