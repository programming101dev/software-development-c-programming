#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void print_array(const int arr[], size_t size);

int main(void)
{
    const int arr[] = {1, 2, 3, 4, 5};

    print_array(arr, 5);

    return EXIT_SUCCESS;
}

static void print_array(const int arr[], size_t size)
{
    for(unsigned int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
