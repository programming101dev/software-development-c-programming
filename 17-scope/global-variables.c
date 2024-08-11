#include <stdio.h>
#include <stdlib.h>

int globalVar = 0;    // Global variable  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

void example(void);

void example(void)
{
    globalVar++;
    printf("globalVar = %d\n", globalVar);
}

int main(void)
{
    example();    // Prints 1
    example();    // Prints 2
    return EXIT_SUCCESS;
}
