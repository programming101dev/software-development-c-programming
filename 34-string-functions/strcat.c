#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char       dest[50] = "Hello, ";
    const char src[]    = "World!";
    strcat(dest, src);    // NOLINT(clang-analyzer-security.insecureAPI.strcpy)
    printf("Concatenated string using strcat: %s\n", dest);

    return EXIT_SUCCESS;
}
