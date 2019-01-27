#include <stdio.h>

/* This program counts blanks, tabs and newlines
 * To end the input reading Control + D must be pressed in order for the program
 * to execute.
 */

int main() {
    int nb, nt, nl; /* number of blanks, tabs and newlines */
    /* We initialize the variables in order to not get weird numbers */
    nb = 0;
    nt = 0;
    nl = 0;
    int c; /* current character */
    
    while ((c = getchar()) != EOF)
    {
        if (c == ' ') /* blank */
        {
            ++nb;
        }
        if (c == '\t') /* tab */
        {
            ++nt;
        }
        if (c == '\n') /* newline */
        {
            ++nl;
        }
    }

    printf("\nBlanks = %d\nTabs = %d\nNewlines = %d\n", nb, nt, nl);
    
    return 0;
}
