#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int divide(int numerator, int denominator);

static int divide(int numerator, int denominator)
{
    // Ensure denominator is not zero
    assert(denominator != 0);

    return numerator / denominator;
}

int main(void)
{
    int result;

    result = divide(10, 2);
    printf("Result: %d\n", result);

    result = divide(10, 0);    // This will trigger the assert
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}
