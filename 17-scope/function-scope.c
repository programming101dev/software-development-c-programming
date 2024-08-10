#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    int x = 0;

start:
    printf("x = %d\n", x);
    x++;

    if(x < 3)
    {
        goto start;  // Label 'start' is accessible throughout the function
    }
}

int main(void)
{
    example();
    return EXIT_SUCCESS;
}
