#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char str1[] = "Hello, World!";
    const char str2[] = "Hello";
    int        result;

    result = strcmp(str1, str2);
    printf("Comparison of str1 and str2: %d\n", result);

    return EXIT_SUCCESS;
}
