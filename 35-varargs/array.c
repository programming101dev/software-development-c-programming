#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int sum_array(const int *arr, size_t count);

int main(void)
{
    const int    numbers[] = {4, 5, 6, 7};
    const size_t size      = sizeof(numbers) / sizeof(numbers[0]);
    int          sum;

    sum = sum_array(numbers, size);
    printf("Sum of array: %d\n", sum);

    return EXIT_SUCCESS;
}

static int sum_array(const int *arr, size_t count)
{
    int total;

    total = 0;

    for(size_t i = 0; i < count; i++)
    {
        total += arr[i];
    }

    return total;
}
