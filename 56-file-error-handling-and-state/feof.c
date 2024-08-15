#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("example.txt", "r");
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

    if(feof(file))
    {
        printf("End of file reached.\n");
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
