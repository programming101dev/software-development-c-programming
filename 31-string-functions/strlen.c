#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char str[] = "Hello, World!";

    printf("Length of str: %zu\n", strlen(str));

    return EXIT_SUCCESS;
}
