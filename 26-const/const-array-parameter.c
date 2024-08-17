#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void print_array(const int arr[], size_t size);

static void print_array(const int arr[], size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    print_array(arr, 5);

    return EXIT_SUCCESS;
}
