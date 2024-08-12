#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello";
    printf("Comparison of str1 and str2: %d\n", strcmp(str1, str2));
    return 0;
}
