#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;
    bool  continue_reading;

    file = fopen("example.txt", "r");
    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    continue_reading = true;

    while(continue_reading)
    {
        int ch;
        ch = fgetc(file);
        if(ch != EOF)
        {
            // Process character
            putchar(ch);
        }
        else
        {
            continue_reading = false;
        }
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
