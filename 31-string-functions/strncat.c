#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char       dest[50] = "Hello, ";
    const char src[]    = "C Programming!";

    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("Concatenated string using strncat: %s\n", dest);

    return EXIT_SUCCESS;
}
