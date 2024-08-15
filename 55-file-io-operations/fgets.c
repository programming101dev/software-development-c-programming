#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("example.txt", "r");    // NOLINT (android-cloexec-fopen)
    char  buffer[256];

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
