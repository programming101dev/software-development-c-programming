#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *p, size_t size);

void print_array(const int *p, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        printf("%d ", p[i]);
    }

    printf("\n");
}

int main(void)
{
    const int arr[] = {1, 2, 3, 4, 5};
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    return EXIT_SUCCESS;
}
