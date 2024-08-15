#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE  *file = fopen("example.txt", "r");
    fpos_t pos;
    long   currentPos;

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Get the current file position
    if(fgetpos(file, &pos) != 0)
    {
        perror("fgetpos");
        if(fclose(file) != 0)
        {
            perror("fclose");
        }
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

    // Restore the previous file position
    if(fsetpos(file, &pos) != 0)
    {
        perror("fsetpos");
        if(fclose(file) != 0)
        {
            perror("fclose");
        }
        return EXIT_FAILURE;
    }

    // Verify the restored position
    currentPos = ftell(file);

    if(currentPos == -1L)
    {
        perror("ftell");
    }
    else
    {
        printf("Restored file position: %ld\n", currentPos);
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
