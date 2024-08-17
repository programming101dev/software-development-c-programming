#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char str1[] = "Hello, World!";
    const char str2[] = "Hello";

    printf("Comparison of str1 and str2: %d\n", strcmp(str1, str2));

    return EXIT_SUCCESS;
}
