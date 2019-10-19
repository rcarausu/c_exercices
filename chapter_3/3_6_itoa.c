#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define MAXLINE 1000

void get_line(char s[]);
int number_width(int n);
void itoa(int n, char s[], int pad);
void reverse(char s[]);

/*
 * Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width, the converted number must 
 * be padded with blanks on the left if necessary to make it wide enough.
 */

int main(int argc, char *argv[])
{
    char s[MAXLINE];

    printf("Insert an integer number: ");
    get_line(s);
    int i = atoi(s);
    printf("Insert a padding: ");
    get_line(s);
    int p = atoi(s);

    printf("Number %d, padding %d\n", i, p);

    printf("Number width: %d\n", number_width(i));

    itoa(i, s, p);

    printf("result of atoi with padding: %s\n", s);

    return 0;
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

int number_width(int n)
{
    int l = 0;
    while (n != 0) 
    {
        n /= 10;
        l++;
    }

    return l;
}

void itoa(int n, char s[], int pad)
{
    int i, sign, length;

    sign = n;
    length = number_width(n);

    i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);

    if (sign < 0)
        s[i++] = '-';

    while (i < (pad + length)) 
        s[i++] = '_';

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
