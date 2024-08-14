#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    const int x = 10;
    int       y;

    y = x + 5;    // Proper initialization
    printf("y = %d\n", y);
}

int main(void)
{
    example();
    return EXIT_SUCCESS;
}
