#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file = fopen("example.bin", "rb");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int buffer[10];
    size_t bytesRead = fread(buffer, sizeof(int), 10, file);
    if (bytesRead != 10) {
        if (feof(file)) {
            printf("End of file reached.\n");
        } else if (ferror(file)) {
            perror("fread");
        }
    }

    if (fclose(file) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
