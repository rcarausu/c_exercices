#include <stdlib.h>
#include <stdio.h>

void get_line(char s[]);
int strrindex(char s[], char t[]);


#define MAXLINE 1000



/* Write  the function strrindex(s, t) which returns the position
 * of the rightmost occurence of t in s,m or -1 if there is none.
 */

int main(int argc, char *argv[])
{
    char s[MAXLINE];
    char t[MAXLINE];

    printf("Insert the text for the search: ");
    get_line(s);
    
    printf("Insert the text to search: ");
    get_line(t);

    int index = strrindex(s, t);

    printf("Index for the search is: %d\n", index);

    return 0;
}


int strrindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}


void get_line(char s[])
{
    int i, c;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
}

