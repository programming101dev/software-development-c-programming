#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello";
    printf("Comparison of first 5 characters: %d\n", strncmp(str1, str2, 5));
    printf("Comparison of first 7 characters: %d\n", strncmp(str1, str2, 7));
    return 0;
}
