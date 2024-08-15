#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("example.txt", "r");
    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fgetc(file);    // Attempting to read the first character

    if(ferror(file))
    {
        fprintf(stderr, "An error occurred while reading the file.\n");
        clearerr(file);
    }

    if(ferror(file))
    {
        fprintf(stderr, "Error not cleared.\n");
    }
    else
    {
        printf("Error cleared successfully.\n");
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
