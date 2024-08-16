#include <stdio.h>
#include <stdlib.h>
#include "math_operations.h"

int main(void)
{
    const int a = 10;
    const int b = 5;

    printf("Add: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtract: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiply: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Divide: %d / %d = %d\n", a, b, divide(a, b));
    printf("Divide: %d / %d = %d\n", a, 0, divide(a, 0));

    return EXIT_SUCCESS;
}
