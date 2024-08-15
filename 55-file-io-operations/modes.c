#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *textFile   = fopen("example.txt", "r");
    FILE *binaryFile = fopen("example.bin", "rb");

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
