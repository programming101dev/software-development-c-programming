#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char        str[] = "Hello, World!";
    const char *result;

    result = memchr(str, 'W', strlen(str));

    if(result)
    {
        ptrdiff_t diff;

        diff = result - str;
        printf("Found 'W' at position: %td\n", diff);
    }
    else
    {
        printf("'W' not found.\n");
    }

    return EXIT_SUCCESS;
}
