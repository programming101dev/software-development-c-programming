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

    // Intentionally causing an error
    fgetc(file);
    fgetc(file);
    clearerr(file);

    if(ferror(file))
    {
        fprintf(stderr, "An error occurred while reading the file.\n");
    }
    else
    {
        printf("No error occurred.\n");
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
