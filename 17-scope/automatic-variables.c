#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    int x = 10; // Automatic variable
    printf("x = %d\n", x);
} // x is destroyed here

int main(void)
{
    example();
    return EXIT_SUCCESS;
}
