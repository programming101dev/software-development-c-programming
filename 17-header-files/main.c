#include "math_operations.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int numbers[] = {3, 5, 7, 2, 8};
    size_t    size;
    int       sum;
    int       max;

    size = sizeof(numbers) / sizeof(numbers[0]);
    sum  = sum_elements(numbers, size);
    max  = max_element(numbers, size);
    printf("Sum of elements: %d\n", sum);
    printf("Maximum element: %d\n", max);

    return EXIT_SUCCESS;
}
