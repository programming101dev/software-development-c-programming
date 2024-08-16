#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int  a      = -5;
    const int  b      = 10;
    const bool result = (a > 0 || b > 0);

    printf("Result of %d || %d operation: %d\n", a, b, result);

    return EXIT_SUCCESS;
}
