#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define MAXLINE 1000

void get_line(char s[]);
void itoa(int n, char s[]);
void reverse(char s[]);

/*
 * In a two's complement number representation, our version of itoa does
 * not handle the largest negative number, that is, the value of n equal
 * to -(2^(wordsize-1)). Explain why not. Modify it to print that value 
 * correctly, regardless of the machine on which it runs.
 */

/*
 * Answer: explanation is quite long, check https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_3:Exercise_4
*/

int main(int argc, char *argv[])
{
    char s[MAXLINE];
    int i = 3242234;

    // get_line(s);
    itoa(i, s);

    printf("result: %s\n", s);
    printf("expected: %d\n", i);
    printf("Testing with INT_MIN\n");
    itoa(INT_MIN, s);
    printf("result: %s\n", s);
    printf("expected: %d\n", INT_MIN);
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

void itoa(int n, char s[])
{
    int i, sign;

    sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{

    int i = 0;
    char aux;

    int j = strlen(s) - 1;
    while (i < j)
    {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
        j--;
        i++;
    }
}
