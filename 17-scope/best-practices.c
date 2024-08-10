#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    static int counter = 0; // Prefer static or local scope
    counter++;
    printf("counter = %d\n", counter);
}

int main(void)
{
    example(); // Prints 1
    example(); // Prints 2
    return EXIT_SUCCESS;
}
