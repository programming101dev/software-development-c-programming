#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int divide(int numerator, int denominator);

int main(void)
{
    int result;

    result = divide(10, 2);
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}

static int divide(int numerator, int denominator)
{
    // Precondition
    assert(denominator != 0 && "Denominator must not be zero");

    return numerator / denominator;
}
