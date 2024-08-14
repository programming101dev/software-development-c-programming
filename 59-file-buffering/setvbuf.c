#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buf[1024];  // User-allocated buffer
    if (setvbuf(file, buf, _IOFBF, sizeof(buf)) != 0) {
        perror("setvbuf");
        if (fclose(file) != 0) {
            perror("fclose");
        }
        return EXIT_FAILURE;
    }

    fprintf(file, "This is a test.\n");  // Data will be fully buffered

    if (fclose(file) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
