#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;
    bool  continue_reading;

    // Open the file for reading
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
            putchar(ch);
        }
        else
        {
            continue_reading = false;
        }
    }

    // Close the file
    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
