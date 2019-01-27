#include <stdio.h>

/* This program copies input to output replacing
 * each string of one or more blanks by a single blank
 */

void usage() {
    printf("Press Ctrl+C to terminate the program\n");
    printf("Hit Enter to execute the copy after finishing writing the input\n");
}

int main() {
    // check if previous char is blank. Do not put cha if so
    int c, pc; // current and previous character.

    usage();

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (pc != ' ')
            {
                putchar(c);
            }
        }
        if (c != ' ') {
            putchar(c);
        }
        
        pc = c;
    }

    return 0;
}

