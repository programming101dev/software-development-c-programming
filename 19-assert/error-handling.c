#include <stdio.h>
#include <stdlib.h>

static int divide(int numerator, int denominator, int *result);

static int divide(int numerator, int denominator, int *result)
{
    if(denominator == 0)
    {
        return -1;    // Return error code for division by zero
    }
    *result = numerator / denominator;
    return 0;    // Return success code
}

int main(void)
{
    int result = 0;

    if(divide(10, 2, &result) == 0)    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    {
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Error: Division by zero\n");
    }

    if(divide(10, 0, &result) == 0)    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    {
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Error: Division by zero\n");
    }

    return EXIT_SUCCESS;
}
