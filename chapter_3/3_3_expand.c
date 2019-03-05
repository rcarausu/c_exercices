#include <stdio.h>

#define MAXLINE 1000


void expand(char s1[], char s2[]);
void get_line(char s[]);

/*
 * Write a function expand(s1, s2) that expands shorthand notations like a-z 
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, and be prepared to handle cases 
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is 
 * taken literally 
 */

/* The last phrase means that a leading or traling - is printed as is */

int main(int argc, char *argv[]) {

	char s1[MAXLINE];
	char s2[MAXLINE];

	get_line(s1);

	expand(s1, s2);

	printf("%s\n",s2);

	return 0;
}

void get_line(char s[]) {
    int i,c;

    for(i=0; i < MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i]=c;

    if(c=='\n')
        s[i++]=c;
    
    s[i]='\0';
}

void expand(char s1[], char s2[]) {

	char c;

	int i = 0;
	// int j = 0;
	int k = 0;

	while (s1[i+1] != '\0') {
		if (s1[i+1] == '-' && s1[i] < s1[i+2]) {
			c = s1[i];
			while (c < s1[i+2]) {
				s2[k++] = c++;
			}
			i = i + 2;		
		} else {
			s2[k++] = s1[i];
			++i;
		}
		
	}

	s2[k] = '\0';	
}
