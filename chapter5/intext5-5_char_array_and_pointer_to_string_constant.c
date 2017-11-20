#include<stdio.h>

int main()
{
	char amessage[] = "now is the time"; //character array
	char *pmessage = "now is the time"; // pointer to string constant
	
	printf("amessage : %s\n",amessage);
	printf("pmessage : %s\n",pmessage);

	amessage[0] = 'N';
	printf("amessage : %s\n",amessage);
	
/* this gives segmentation fault
	pmessage[0] = 'N';
	printf("pmessage : %s\n",pmessage);
	*/

	pmessage ++;
	printf("pmessage : %s\n",pmessage);

	/* give error
	amessage ++;
	printf("amessage : %s\n",amessage);
	*/
	return 0;
}
