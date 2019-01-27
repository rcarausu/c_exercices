#include <stdio.h>

/* Program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, 
 * and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 */

int main() {
    int a,c;

    while ((c = getchar()) != EOF) {
        a = 0; // We use this char to control wheter c is one of the special chars or not.
        if (c == '\t') {
            putchar('\\');
            putchar('t');
            a = 1;
        }
        if (c == '\b') {
            putchar('\\');
            putchar('b');
            a = 1;
        }
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
            a = 1;
        }
        if (a == 0) {
            putchar(c);
        }
    }

    return 0;
}

