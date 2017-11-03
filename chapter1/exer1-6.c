#include<stdio.h>

int main()
{
	int c;
	int d;
	while(d= ((c=getchar())!=EOF))
	{
		printf("%d",d);
		putchar(c);
	}
}

/* Notes
1. Enter / Carraige Return is treated as a character and ALSO FLUSHES BUFFER.
2. Ctrl + D :
	if used at start of line - ends program
	if used after some input - flushes buffer (and if used once again immediately - ends program)
*/
