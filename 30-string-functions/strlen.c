#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char str[] = "Hello, World!";
    size_t     len;

    len = strlen(str);
    printf("Length of str: %zu\n", len);

    return EXIT_SUCCESS;
}
