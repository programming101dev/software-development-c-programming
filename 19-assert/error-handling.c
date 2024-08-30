#include <stdio.h>
#include <stdlib.h>

static int divide(int numerator, int denominator, int *result);

int main(void)
{
    int result;
    int error;

    result = 0;
    error = divide(10, 2, &result);

    if(error == 0)
    {
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Error: Division by zero\n");
    }

    error = divide(10, 0, &result);

    if(error == 0)
    {
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Error: Division by zero\n");
    }

    return EXIT_SUCCESS;
}

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
