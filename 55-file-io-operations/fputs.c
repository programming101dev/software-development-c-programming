#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *text = "Hello, World!";
    FILE       *file = fopen("example.txt", "w");

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    if(fputs(text, file) == EOF)
    {
        perror("fputs");
        if(fclose(file) != 0)
        {
            perror("fclose");
        }
        return EXIT_FAILURE;
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
