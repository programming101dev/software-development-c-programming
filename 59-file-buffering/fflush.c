#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("example.txt", "w");
    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fprintf(file, "This is a test.");
    fflush(file);    // Ensure the data is written to the file immediately

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
