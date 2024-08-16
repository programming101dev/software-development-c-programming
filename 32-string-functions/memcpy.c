#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char src[] = "Hello, World!";
    char       dest[50];
    memcpy(dest, src, strlen(src) + 1);    // +1 to include the null terminator
    printf("Copied string using memcpy: %s\n", dest);

    return EXIT_SUCCESS;
}
