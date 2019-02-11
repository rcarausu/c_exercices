#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
 * In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 */

/* ANSWER (from https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_9)
 *
 * If x is odd, then (x-1) has the same bit representation as x except that 
 * the rightmost 1-bit is now a 0. In this case, (x & (x-1)) == (x-1).
 *
 * If x is even, then the representation of (x-1) has the rightmost zeros of x 
 * becoming ones and the rightmost one becoming a zero. Ading the two clears the 
 * rightmost 1-bit in x and all the rightmost 1-bits from (x-1). 
 */

// counts 1 bits in x
int bitcount(unsigned x) {
	int b;

	for (b = 0; x != 0; x &= (x-1))
		b++;
	return b;
}

int main(int argc, char *argv[]) {

	return 0;
}
