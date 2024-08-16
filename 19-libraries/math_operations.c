#include "math_operations.h"

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    int result;

    if(b == 0)
    {
        result = 0;
    }
    else
    {
        result = a / b;
    }

    return result;
}
