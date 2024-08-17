#include <stdio.h>
#include <stdlib.h>

void example(void);

int main(void)
{
    example();
    // printf("%d\n", x); // Error: x is not accessible here

    return EXIT_SUCCESS;
}

void example(void)
{
    int x;

    x = 10;
    printf("x = %d\n", x);
}
