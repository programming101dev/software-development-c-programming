#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

int main(void)
{
    const char str1[13] = "Hello, World!";
    const char str2[]   = "Hello, World!";
    // cppcheck-suppress unusedVariable
    char str3[10];    // Declaration without initialization

    printf("%s\n", str1);
    printf("%s\n", str2);

    return EXIT_SUCCESS;
}

#pragma GCC diagnostic pop
