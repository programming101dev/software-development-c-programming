#include <stdio.h>
#include <stdlib.h>

static int divide(int numerator, int denominator, int *result);

static int divide(int numerator, int denominator, int *result)
{
    int status;

    if(denominator == 0)
    {
        status = -1;
    }
    else
    {
        status  = 0;
        *result = numerator / denominator;
    }

    return status;
}

int main(void)
{
    int result = 0;

    if(divide(10, 2, &result) == 0)
    {
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Error: Division by zero\n");
    }

    if(divide(10, 0, &result) == 0)
    {
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Error: Division by zero\n");
    }

    return EXIT_SUCCESS;
}
