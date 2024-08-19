#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char str[] = "Hello, World!";

    for(size_t i = 0; str[i] != '\0'; i++)
    {
        printf("Index %zu: %c\n", i, str[i]);
    }

    return EXIT_SUCCESS;
}
