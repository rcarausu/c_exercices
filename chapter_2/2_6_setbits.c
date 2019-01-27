#include <stdio.h>
#include <stdlib.h>


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

	unsigned x = atoi(argv[1]);
	int p = atoi(argv[2]);
	int n = atoi(argv[3]);

	printf("getbits(%d, %d, %d): %d\n", x, p, n, getbits(x, p, n));

	printf("%d\n", setbits(684, 8, 4, 3182));

	return 0;
}
