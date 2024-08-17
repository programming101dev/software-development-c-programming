#include "math_operations.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1;
    int num2;
    int sum;
    int difference;

    num1       = 10;
    num2       = 5;
    sum        = add(num1, num2);
    difference = subtract(num1, num2);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);

    return EXIT_SUCCESS;
}
