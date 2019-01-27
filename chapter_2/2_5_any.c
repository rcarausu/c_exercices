#include <stdio.h> 

/*
 * Write the function any(s1, s2) which returns the first location in s1
 * where any character from s2 occurs, or -1 if it doesn't
*/

#define TRUE 1
#define FALSE 0

int contains_char(char str[], char c) {
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			return TRUE;
	}
	return FALSE;
}

int any(char s1[], char s2[]) {
    int i, is_present;
    
    for  (i = 0; s1[i] != '\0'; i++) {
    	is_present = contains_char(s2, s1[i]);
    	if (is_present)
    		return i;
    }
    return -1;
}


void main() {
    char s1[] = "hello world!";
    char s2[] = "aeiou";
    printf("The result of any is %d\n", any(s1, s2));
}