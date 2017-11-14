#include<stdio.h>
#include "bar.h"

int main(void)
{
	printf("This is a shared library - test\n");
	bar();
	return 0;
}
