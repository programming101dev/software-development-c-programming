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
        putchar(ch);
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
