#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        // Process character
        putchar(ch);
    }

    if (feof(file)) {
        printf("\nEnd of file reached.\n");
    } else if (ferror(file)) {
        perror("fgetc");
    }

    if (fclose(file) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
