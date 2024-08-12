#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("i = %d, j = %d\n", i, j);
        }
    }
    return EXIT_SUCCESS;
}
