#include <stdio.h>

#define MAX_LENGTH  100
#define IN          1    // inside a word
#define OUT         0    // outside a word

void usage() {
    printf("**** Word histogram (horizontal) ****\n");
    printf("Program that prints the histogram of the length of the words of its input\n");
    printf("Usage: write the input and press Ctrl+D when finished\n");
}

int main() {

    int length[100];
    int c, state, aux;

    state = IN;
    aux = 0;

    usage();

    for (int i = 0; i < MAX_LENGTH; i++)
        length[i] = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state == OUT;
            if (aux != 0) {
                if (aux > MAX_LENGTH) {
                	length[MAX_LENGTH - 1]++;
                } else {
                    length[aux]++;
                }
                aux = 0;
            }
        }
        else if (state == OUT)
            state = IN;

        if (state == IN)
            aux++;
        
    }

    for (int i = 1; i < MAX_LENGTH + 1; i++) {
        if (length[i] > 0) {
            printf("%d\t", i);
            for (int j = 0; j < length[i]; j++)
                printf("+");
            printf("\n");
        }
    }

    return 0;
}
