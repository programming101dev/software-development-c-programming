#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *text;
    const char *p;
    FILE       *file;
    bool        continue_writing;

    text = "Hello, World!";
    file = fopen("example.txt", "w");

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    p                = text;
    continue_writing = true;

    while(continue_writing)
    {
        if(*p != '\0')
        {
            if(fputc(*p, file) == EOF)
            {
                perror("fputc");
                continue_writing = false;
            }
            else
            {
                p++;
            }
        }
        else
        {
            continue_writing = false;
        }
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
