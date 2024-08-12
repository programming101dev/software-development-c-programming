#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    static int x = 0;    // Static variable
    x++;
    printf("x = %d\n", x);
}

int main(void)
{
    example();    // Prints 1
    example();    // Prints 2
    return EXIT_SUCCESS;
}
