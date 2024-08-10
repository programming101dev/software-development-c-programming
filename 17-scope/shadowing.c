#include <stdio.h>
#include <stdlib.h>

void example(void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

const int x = 10; // Global variable

void example(void)
{
    const int x = 20; // Local variable shadows the global variable

    printf("x = %d\n", x); // Prints 20
    {
        const int x = 30; // This variable shadows the previous local variable
        printf("x = %d\n", x); // Prints 30
    }

    printf("x = %d\n", x); // Prints 20
}

#pragma GCC diagnostic pop

int main(void)
{
    example();
    return EXIT_SUCCESS;
}
