#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char str[]     = "Hello, World!";
    char      *duplicate = strdup(str);

    if(duplicate == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Duplicated string: %s\n", duplicate);
    free(duplicate);    // Free the allocated memory

    return EXIT_SUCCESS;
}
