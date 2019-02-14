#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100


/*
 * Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t 
 * as it copies the string t to s. Use a switch. Write  a function 
 * for the other direction as well, converting escape sequences into 
 * real characters.
 */

void escape(char* s, char* t) {
    int i, j;
    i = j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n': 
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }
    s[j] = t[i];
}

void unescape(char* s, char* t) {
    int i, j;
    i = j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\\':
                switch (t[++i]) {
                    case 'n': 
                        s[j] = '\n';
                        break;
                    case 't':
                        s[j] = '\t';
                        break;
            }
            default:
                s[j] = t[i];

        }
        ++i;
        ++j;
    }
    s[j] = t[i];
}

int main(int argc, char *argv[]) {

    char t[MAXLINE] = "\thello\nworld"; 
    char s[MAXLINE];
    char r[MAXLINE] = "\thello\nworld";
    char q[MAXLINE];

    printf("original: %s\n", t);
    escape(s, t);
    printf("escaped: %s\n", s);
    unescape(q, r);
    printf("unsecaped: %s\n", q);

	return 0;
}
