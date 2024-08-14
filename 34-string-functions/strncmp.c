#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str1[] = "Hello, World!";
    const char str2[] = "Hello.";

    printf("Comparison of first 5 characters: %d\n", strncmp(str1, str2, 5));
    printf("Comparison of first 7 characters: %d\n", strncmp(str1, str2, 6));

    return 0;
}
