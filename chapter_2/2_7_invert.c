#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
 * Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted
 * (i.e., 1 changed into 0 and viceversa), leaving the other bits unchanged.
*/

unsigned invert_bits(unsigned x, int p, int n) {
	// 000011110000
	unsigned a = ~(~0U << n) << p;

	// the bitwise exlusive or operator ( ^ ) sets one in each bit position where
	// its operands have different bits and zero where they are the same
	return x ^ a;
}

int main(int argc, char *argv[]) {

	unsigned x = 60;
	int p = 3;
	int n = 2;

	assert (36U == invert_bits(x, p, n));

	printf("assert 36 == 36 is correct\n");

	return 0;
}
