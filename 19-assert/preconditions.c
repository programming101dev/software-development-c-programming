#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int divide(int numerator, int denominator);

static int divide(int numerator, int denominator)
{
    assert(denominator != 0 && "Denominator must not be zero");
    return numerator / denominator;
}

int main(void)
{
    int result = divide(10, 2);    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    printf("Result: %d\n", result);
    return EXIT_SUCCESS;
}
