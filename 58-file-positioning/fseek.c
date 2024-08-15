#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("example.txt", "r");
    int   ch;

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

    // Read and print the character at the new position
    ch = fgetc(file);

    if(ch != EOF)
    {
        printf("Character at position 10: %c\n", ch);
    }
    else
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
