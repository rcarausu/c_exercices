#include <stdio.h>

#define MAXLINE 100 // maximum input line size

// Program that reverses input lines

int getline2(char line[], int maxline);
int line_length(char from[]);
void reverse(char from[], char to[]);

int main()
{	
	int len;
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0)
    {
        printf("length: %d\n", len);
        char reversed[len];
        reverse(line, reversed);
	    printf("reversed: %s\n", reversed);	
    }
    return 0;
}

int line_length(char from[])
{
    int i = 0;
    
    char c = from[i];
    while (c != '\0')
        c = from[i++];
    
    return i;
}

void reverse(char from[], char to[])
{
    int size = line_length(from);    
    int j = size-2;
    
    for (int i=0; i<size; i++) {
        to[i] = from[j];
        j--;
    }
    to[size-1] = '\0';
}

int getline2(char s[], int lim)
{
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		if (i <= lim-1) {
			s[i] = c;
			++i;
		}
		else
			++i;

		if (c == '\n') {
			if (i <= lim-1) {
				s[i] = c;
				++i;
			} else 
				++i;
		}

	}
	
	s[i] = '\0';

	return i;
}
