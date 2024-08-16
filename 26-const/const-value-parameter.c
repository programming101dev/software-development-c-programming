#include <stdio.h>
#include <stdlib.h>

void print_value(int x);

void print_value(const int x)
{
    printf("Value: %d\n", x);
    // x = 20;  // Error: x is read-only
}

int main(void)
{
    const int x = 10;
    print_value(x);

    return EXIT_SUCCESS;
}