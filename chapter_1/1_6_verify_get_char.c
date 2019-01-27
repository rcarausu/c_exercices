#include <stdio.h>

int main () {
    /* Verifying that getchar() != EOF is 0 or 1 */
    /* PS: it's 1 */
    printf("%d\n", getchar() != EOF);
    return 0;
}
