#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

const int x = 10;

int main(void)
{
    // cppcheck-suppress shadowVariable
    const int x = 20;

    printf("x = %d\n", x);    // Prints 20
    {
        // cppcheck-suppress shadowVariable
        const int x = 30;
        printf("x = %d\n", x);
    }

    printf("x = %d\n", x);

    return EXIT_SUCCESS;
}

#pragma GCC diagnostic pop
