#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int divide(int numerator, int denominator);

static int divide(int numerator, int denominator)
{
    assert(denominator != 0);    // Ensure denominator is not zero
    return numerator / denominator;
}

int main(void)
{
    int result = divide(10, 2);
    printf("Result: %d\n", result);

    result = divide(10, 0);    // This will trigger the assert
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}
