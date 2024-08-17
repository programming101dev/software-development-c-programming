#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void print_array(const int *p, size_t size);

int main(void)
{
    const int    arr[]    = {1, 2, 3, 4, 5};
    const size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, arr_size);

    return EXIT_SUCCESS;
}

static void print_array(const int *p, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        printf("Element %zu: %d\n", i, *(p + i));
    }
}
