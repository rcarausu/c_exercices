#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define OCTET 8

/*
 * The standard headers limits.h and float.h contain symbolic constants for the sizes 
 * of the different datatypes of C.
 */ 

void main() {
	char c;
	short s;
	int i;
	long l;
	float f;
	double d;
 
	printf("**** Ranges of C basic data types *****\n");
	printf("********** SIGNED ***********\n");
	printf("\tsigned char min: %.f\n", -1 * pow(2, (sizeof(c) * OCTET)-1));
	printf("\tsigned char max: %.f\n", pow(2, (sizeof(c) * OCTET)-1)-1);
	printf("\tsigned short min:%.f\n", -1 * pow(2, (sizeof(s) * OCTET)-1));
	printf("\tsigned short max: %.f\n", pow(2, (sizeof(s) * OCTET)-1)-1);
	printf("\tsigned int min: %.f\n", -1 * pow(2, (sizeof(i) * OCTET)-1));
	printf("\tsigned int max: %.f\n", pow(2, (sizeof(i) * OCTET)-1)-1);
	printf("\tsigned long min: %.f\n", -1 * pow(2, (sizeof(l) * OCTET)-1));
	printf("\tsigned long max: %.f\n", pow(2, (sizeof(l) * OCTET)-1)-1);
	printf("********** UNSIGNED **********\n");
	printf("\tunsigned char max: %.f\n", pow(2, (sizeof(c) * OCTET))-1);
	printf("\tunsigned short max: %.f\n", pow(2, (sizeof(s) * OCTET))-1);
	printf("\tunsigned int max: %.f\n", pow(2, (sizeof(i) * OCTET))-1);
	printf("\tunsigned long max: %.f\n", pow(2, (sizeof(l) * OCTET))-1);
	printf("********** FLOATING POINT **********\n");
	printf("\tfloat max: %.2e\n", FLT_MAX); 
	printf("\tfloat min: %.2e\n", FLT_MIN);
	printf("\tdouble min: %.2e\n", DBL_MAX);
	printf("\tdouble min: %.2e\n", DBL_MIN);
}

