//Exercise 1-15
//Rewrite the temperature conversion program of Section 1.2 to use function for coversion
#include<stdio.h>

//function prototypes
float convertCelToFahr(float);

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Fahrenheit Celsius\n");	
	fahr = lower;
	while(fahr <= upper)
	{
		celsius = convertCelToFahr(fahr);
		printf("%10.0f %7.1f\n",fahr,celsius);
		fahr = fahr + step;
	}

	return 0;
}

float convertCelToFahr(float fahr)
{
	float celsius;
	celsius = (5.0/9.0) * (fahr - 32.0);
	return celsius;
}
