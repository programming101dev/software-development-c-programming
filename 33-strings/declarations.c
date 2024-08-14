#include <stdio.h>

int main(void)
{
    const char str1[13] = "Hello, World!";
    const char str2[]   = "Hello, World!";
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
    // cppcheck-suppress unusedVariable
    char str3[10];    // Declaration without initialization
#pragma GCC diagnostic pop

    printf("%s\n", str1);
    printf("%s\n", str2);

    return 0;
}
