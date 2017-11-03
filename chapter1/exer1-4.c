#include<stdio.h>

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Celsius Fahrenheit\n");
	celsius = lower;
	while(celsius <= upper)
	{
		fahr = ((9.0/5.0) * celsius) + 32.0;
		printf("%7.0f %10.1f\n",celsius,fahr);
		celsius = celsius + step;
	}

	return 0;
}
