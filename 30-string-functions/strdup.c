#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char str[] = "Hello, World!";
    char      *duplicate;

    duplicate = strdup(str);

    if(duplicate == NULL)
    {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    printf("Duplicated string: %s\n", duplicate);
    free(duplicate);
    duplicate = NULL;

    return EXIT_SUCCESS;
}
