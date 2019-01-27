#include <stdio.h>

/* This program prompts for input, and then captures a character from 
 * the keyboard. If EOF is signalled (typically through a control-D
 * or control-Z character, though not necesarily), the program prints 0.
 * Otherwise, it prints 1.
 *
 * If your input stream is buffered (and it probably is), then you 
 * need to press the ENTER key before the program will respond.
 */

int main () {
    printf("%d\n", EOF);
    return 0;
}
