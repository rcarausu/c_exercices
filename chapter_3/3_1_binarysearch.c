#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


/*
 * Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a 
 * version with only one test inside the loop and measure the
 * difference in run-time.
 */

int binarysearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid; // found match
    }

    return -1; // no match
}

int binarysearch2(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
        
    }

    if (x == v[mid]) {
        return mid;
    }

    return -1; // no match
}

int main(int argc, char *argv[]) {

    // clock gives the number of ticks since execution of the program

    int n = 5;
	int ordered[n];
    int x = 2;
    int i = 0;

    while (i < n) {
        ordered[i] = i++;
    }

    clock_t begin;
    clock_t end;
    int result;
    int time_spent;

    begin = clock();

    result = binarysearch(x, ordered, n);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("binarysearch: %f clocks\n", (double)(end - begin));

    begin = clock();

    result = binarysearch2(x, ordered, n);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("binarysearch2: %f clocks\n", (double)(end - begin));

    
    assert(result == 3);
    printf("assert 1 == %d\n", result);

	return 0;
}
