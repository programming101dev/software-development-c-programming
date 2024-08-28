#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[] = "Hello, World!";

    memmove(str + 7, str, 5);
    printf("%s\n", str);

    return EXIT_SUCCESS;
}
