#include <stdio.h>
#include <stdlib.h>

static void print_value(int x);

int main(void)
{
    const int x = 10;
    print_value(x);

    return EXIT_SUCCESS;
}

static void print_value(const int x)
{
    printf("Value: %d\n", x);
    // x = 20;  // Error: x is read-only
}
