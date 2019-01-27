#include <stdio.h>

/*
 * Write an alternate version of squeeze(s1, s2) that deletes eachy character in s1 that
 * matches any character in the string s2.
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

void squeeze(char s1[], char s2[]) {
    int i, j, is_present;
    
    for  (i = j = 0; s1[i] != '\0'; i++) {
    	is_present = contains_char(s2, s1[i]);
    	if (is_present == FALSE) {
    		// this may provoque a seg fault if s1 is declared as a 'string literal'
    		// string literals cannot be modified
    		s1[j++] = s1[i];
    	}
    }
    s1[j] = '\0';
}

void main() {
    char s1[] = "hello world!";
    char s2[] = "aeiou";
    squeeze(s1, s2);
    printf("% s\n", s1);
}
