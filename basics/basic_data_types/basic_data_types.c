//Basic data types and sizes

#include<stdio.h>

//#include<values.h>
/* This interface is obsolete.  New programs should use
   <limits.h> and/or <float.h> instead of <values.h>.  */


/* /usr/include/limits.h> */
#include<limits.h>

/* /usr/lib/gcc/x86_64-linux-gnu/5.4.0/include/float.h */
#include<float.h>

 

int main()
{
	//char
	char ch;
	signed char ch_signed;
	unsigned char ch_unsigned;

	//int
	int i;
	signed int i_signed;
	unsigned int i_unsigned;

	short int i_short;		 				//short i_short;
	signed short int i_short_signed;
	unsigned short int i_short_unsigned;

	long int i_long;						//long i_long;
	signed long int i_long_signed;
	unsigned long int i_long_unsigned;
	
	//float
	float f; 								//single precision
	
	//double
	double d;								//double precision
	long double d_long;						//extended double precision

	//print size and range of above data types
	//note : return type of sizeof() is long unsigned int

	//char
	printf("char(signed) \t\t%ld byte\t Min: %d\t\t\tMax: %d\n",sizeof(ch),SCHAR_MIN,SCHAR_MAX);
	printf("signed char \t\t%ld byte\t Min: %d\t\t\tMax: %d\n",sizeof(ch_signed),SCHAR_MIN,SCHAR_MAX);
	printf("unsigned char \t\t%ld byte\t Min: %d\t\t\t\tMax: %d\n\n",sizeof(ch_unsigned),0,UCHAR_MAX);
	//int
	printf("int(signed)\t\t%ld byte\t Min: %d\t\tMax: %d\n",sizeof(i),INT_MIN,INT_MAX);
	printf("signed int \t\t%ld byte\t Min: %d\t\tMax: %d\n",sizeof(i_signed),INT_MIN,INT_MAX);
	printf("unsigned int \t\t%ld byte\t Min: %d\t\t\t\tMax: %u\n\n",sizeof(i_unsigned),0,UINT_MAX);
	//short
	printf("short int \t\t%ld byte\t Min: %d\t\t\tMax: %d\n",sizeof(i_short),SHRT_MIN,SHRT_MAX);
	printf("signed short int \t%ld byte\t Min: %d\t\t\tMax: %d\n",sizeof(i_short_signed),SHRT_MIN,SHRT_MAX);
	printf("unsigned short int \t%ld byte\t Min: %d\t\t\t\tMax: %d\n\n",sizeof(i_short_unsigned),0,USHRT_MAX);
	//long
	printf("long int \t\t%ld byte\t Min: %ld\tMax: %ld\n",sizeof(i_long),LONG_MIN,LONG_MAX);
	printf("signed long int \t%ld byte\t Min: %ld\tMax: %ld\n",sizeof(i_long_signed),LONG_MIN,LONG_MAX);
	printf("unsigned long int \t%ld byte\t Min: %d\t\t\t\tMax: %lu\n\n",sizeof(i_long_unsigned),0,ULONG_MAX);
	//float
	printf("float \t\t\t%ld byte\t Min: %e\t\tMax: %e\n\n",sizeof(f),FLT_MIN,FLT_MAX);//float.h
	//we get value for MINFLOAT as 0.00000 if used %f instead of %e, same for mindouble and long min double
	
	//double
	printf("double \t\t\t%ld byte\t Min: %e\t\tMax: %e\n",sizeof(d),DBL_MIN,DBL_MAX);//float.h
	printf("long double \t\t%ld byte\t Min: %Le\t\tMax: %Le\n",sizeof(d_long),LDBL_MIN,LDBL_MAX);//float.h

	return 0;
}

//Note : Refer to <limits.h> and <float.h> which contain symbolic constants for all sizes.
