#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void print_array(const int arr[], size_t size);

int main(void)
{
    const int    numbers[] = {1, 2, 3, 4, 5};
    const size_t size      = sizeof(numbers) / sizeof(numbers[0]);    // Calculates the number of elements

    print_array(numbers, size);

    return EXIT_SUCCESS;
}

static void print_array(const int arr[], size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
