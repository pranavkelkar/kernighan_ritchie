#include<stdio.h>
#include"intext1-10_header.h"

/* mygetline : specialized version */
int mygetline(void)
{
	int c, i;
	extern char line[];
	//If definition of an external variable occurs in the source file
	//before its use in a particular funtion, then there is no need for
	//an external declaration in the function.
	//**different source files, hence external declaration is a necessity

	for(i=0; i< MAXLINE-1 && (c = getchar())!=EOF && c!='\n' ; ++i)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = c;
		++i;
	}
	
	line[i] = '\0';
	return i;
}

/* copy : specialized version */
void copy(void)
{
	int i;
	extern char line[], longest[];
	//If definition of an external variable occurs in the source file
	//before its use in a particular funtion, then there is no need for
	//an external declaration in the function.
	//**different source files, hence external declaration is a necessity

	i= 0;
	while((longest[i] = line[i]) != '\0')
		++i;
}
