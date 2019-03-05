#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define MAXLINE 1000

void itob(int n, char s[], int b);
void get_line(char s[]);
void reverse(char s[]);

/*
 * Write the function itob(n, s, b) that converts the integer n into a base b character representation
 * in the string s. In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
 */

int main(int argc, char *argv[])
{
    char number[MAXLINE];
    char base[MAXLINE];
    char s[MAXLINE];

    printf("Insert number (base 10): ");
    get_line(number);
    int n = atoi(number);
    printf("Insert base: ");
    get_line(base);
    int b = atoi(base);
    
    itob(n, s, b);

    printf("result: %s\n", s);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign;
    char digits[MAXLINE] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (b < 2 || b > strlen(digits)) 
    {
        fprintf(stderr, "Base %d is not supported\n", b);
        fprintf(stderr, "Supported bases go from 2 to %d\n", strlen(digits));
        exit(-1);
    }

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
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