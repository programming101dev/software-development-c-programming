#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char str1[] = "Hello, World!";
    const char str2[] = "Hello. W";
    int        result;

    result = strncmp(str1, str2, 1);
    printf("Comparison of first 1 characters: %d\n", result);
    result = strncmp(str1, str2, 2);
    printf("Comparison of first 2 characters: %d\n", result);
    result = strncmp(str1, str2, 3);
    printf("Comparison of first 3 characters: %d\n", result);
    result = strncmp(str1, str2, 4);
    printf("Comparison of first 4 characters: %d\n", result);
    result = strncmp(str1, str2, 5);
    printf("Comparison of first 5 characters: %d\n", result);
    result = strncmp(str1, str2, 6);
    printf("Comparison of first 6 characters: %d\n", result);
    result = strncmp(str1, str2, 7);
    printf("Comparison of first 7 characters: %d\n", result);
    result = strncmp(str1, str2, 8);
    printf("Comparison of first 8 characters: %d\n", result);

    return EXIT_SUCCESS;
}
