#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("example.txt", "r");    // NOLINT (android-cloexec-fopen)
    int   ch;

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while((ch = fgetc(file)) != EOF)
    {
        // Process character
        putchar(ch);
    }

    if(feof(file))
    {
        printf("\nEnd of file reached.\n");
    }
    else if(ferror(file))
    {
        perror("fgetc");
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
