#include <stdio.h>

#define MINLINE 10
#define MAXLINE 100 // maximum input line size

// Program that prints lines that are longer than MINLINE characters

int getline2(char line[], int maxline);
void copy2(char to[], char from[]);

int main()
{	
	int len;
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0)
		if (len > MINLINE)
		    printf("%s\n", line);	

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
