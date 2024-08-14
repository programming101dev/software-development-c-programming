#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

const int x = 10;    // Global variable

int main(void)
{
    // cppcheck-suppress shadowVariable
    const int x = 20;    // Local variable shadows the global variable

    printf("x = %d\n", x);    // Prints 20
    {
        // cppcheck-suppress shadowVariable
        const int x = 30;    // This variable shadows the previous local variable
        printf("x = %d\n", x);    // Prints 30
    }

    printf("x = %d\n", x);    // Prints 20

    return EXIT_SUCCESS;
}

#pragma GCC diagnostic pop
