/* Shell Sort : D. L. Shell */
/* Shell sort was invented by D. L. Shell(Donald Shell) in 1959. In early stages, far apart
elements are compared, rather than adjacent ones as in simpler interchange sorts.
This tends to eliminate large amount of disorder quickly, so later stages have
less work to do. The interval between compared elements is gradually decreased to one,
at which point the sort effectively becomes an adjacent interchange method */

#include<stdio.h>
#define MAX 20

//function prototypes
int accept(int []);
void shellsort(int [], int);
void display(int [], int);

int main()
{
	int array[MAX];
	int size;
	//accept
	size = accept(array);
	//display
	display(array,size);
	//shellsort
	shellsort(array,size);
	printf("Sorted ");
	display(array,size);
	return 0;
}

int accept(int v[])
{
	int i, size;
	printf("Enter array size (max 20) : ");
	scanf("%d", &size);
	if(size > MAX)
	{
		size = 20;
		printf("Default size set to 20\n");
	}
	for(i = 0; i < size; i++)
	{
		scanf("%d",&v[i]);
	}
	
	return size;
}

void display(int v[],int size)
{
	int i;
	printf("Array : ");
	for(i=0; i < size ; i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	
	for(gap = n/2; gap > 0 ; gap /=2)
	{
		for(i = gap ; i < n; i++)
		{
			for(j = i-gap ; j>=0 && v[j] > v[j+gap]; j-= gap)
			{
				temp = v[j];
				v[j] = v[j+gap]; 
				v[j+gap] = temp;
			}
		}
	}
}
