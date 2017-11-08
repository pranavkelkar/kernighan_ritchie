//program to verify whether string constants can be concatenated at compile time
//this is useful in splitting long strings across several source lines

#include<stdio.h>
#define helloworld "hello, " "world"

int main()
{
	printf("%s\n",helloworld);
	printf("%s\n","my name is " "pranav kelkar");
	return 0;
}
