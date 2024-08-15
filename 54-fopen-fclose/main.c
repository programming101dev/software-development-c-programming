#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("example.txt", "r");    // NOLINT (android-cloexec-fopen)

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Perform file operations...

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
