#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
 * Rewrite the function lower, which converts upper case letters 
 * to lower case, with a conditional expression instead of if-else.
 */

char lower(char c) {
	return (c >= 'A' && c<= 'Z') ? c + 'a' - 'A' : c;
}

int main(int argc, char *argv[]) {

	char string[] = "HELLO WORLD";
	int i = 0;
	while (string[i] != '\0') {
		printf("%c", lower(string[i]));
		i++;
	}
	printf("\n");
	return 0;
}
