#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
	Write a function setbits(x,p,n,y) that returns x with the n bits that begin
	at position p set to the rightmost n bits of y, leaving the other unchanged.
*/

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	// 0000yyyy0000
	unsigned a = (y & ~(~0 << n)) << (p - n);

	// xxxx0000xxxx
	unsigned b = x & (~(~(~0 << n) << (p - n)));

	// xxxxyyyyxxxx
	return a | b;
}

int main(int argc, char *argv[]) {

	/*
	unsigned x = atoi(argv[1]);
	int p = atoi(argv[2]);
	int n = atoi(argv[3]);
	*/
	unsigned x = 684;
	unsigned y = 3182;
	int p = 8;
	int n = 4;

	printf("getbits(%d, %d, %d, %d): %d\n", x, p, n, y, getbits(x, p, n));

	int result = setbits(x, p, n, y);

	assert( result == 748 );

	printf("Assert success, result: %d\n", result);

	return 0;
}
