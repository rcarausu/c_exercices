#include <stdio.h>

#define MAXLINE 100 // maximum input line size

/* 	
	Function variables are called by value,
	except arrays, which when passed as arguments 
	the address of the first position of the array is passed
*/

// Modification to print as much as possible of the line and show its real length

int getline2(char line[], int maxline);
void copy2(char to[], char from[]);

int main() 
{	
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ((len = getline2(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy2(longest, line);
		}

	if (max > 0)
		printf("Longest line: %s\n", longest);
		printf("Total characters: %d\n", max);

    return 0;
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

void copy2(char to[], char from[])
{
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
