#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *textFile   = fopen("example.txt", "r");    // NOLINT (android-cloexec-fopen)
    FILE *binaryFile = fopen("example.bin", "rb");    // NOLINT (android-cloexec-fopen)

    if(textFile == NULL || binaryFile == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Perform file operations...

    fclose(textFile);
    fclose(binaryFile);
    return EXIT_SUCCESS;
}
