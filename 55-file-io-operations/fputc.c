#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *text = "Hello, World!";
    FILE       *file = fopen("example.txt", "w");    // NOLINT (android-cloexec-fopen)

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    for(const char *p = text; *p != '\0'; p++)
    {
        if(fputc(*p, file) == EOF)
        {
            perror("fputc");
            if(fclose(file) != 0)
            {
                perror("fclose");
            }
            return EXIT_FAILURE;
        }
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
