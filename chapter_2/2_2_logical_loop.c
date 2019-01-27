#include <stdio.h>

#define LIMIT 10

void main() {
	char s[LIMIT];
	int i;
	char c;
	// original for loop
	//for (i = 0; i<LIMIT-1 && (c=getchar()) != '\n' && c!=EOF; ++i) {
	i = 0;
	while (i<LIMIT-1) {
		c = getchar();
		if (c != '\n') {
			if (c != EOF)
				s[i] = c;
			else
				break;
		} else
			break;
		++i;
	}
	s[i] = '\0'; // terminating string
	for (i=0; i<LIMIT; ++i) {
		printf("%c\n", s[i]);
	}
}
	
