#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("example.txt", "r");
    long  pos;

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Move the file pointer to the 10th byte from the beginning
    if(fseek(file, 10, SEEK_SET) != 0)
    {
        perror("fseek");

        if(fclose(file) != 0)
        {
            perror("fclose");
        }

        return EXIT_FAILURE;
    }

    // Get the current file position
    pos = ftell(file);

    if(pos == -1L)
    {
        perror("ftell");
    }
    else
    {
        printf("Current file position: %ld\n", pos);
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
