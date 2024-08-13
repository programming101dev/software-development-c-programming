#include <stdlib.h>
#include <stdio.h>

#define ERROR_INVALID_INPUT 2
#define ERROR_FILE_NOT_FOUND 3

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return ERROR_INVALID_INPUT;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return ERROR_FILE_NOT_FOUND;
    }

    // Process the file

    fclose(file);
    return EXIT_SUCCESS;
}
