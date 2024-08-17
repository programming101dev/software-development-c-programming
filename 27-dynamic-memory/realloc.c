#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void modify_array(int *arr, size_t start, size_t end);
static void print_array(const int *arr, size_t size);

int main(void)
{
    const size_t size        = 5;
    const size_t larger_size = size * 2;
    int         *arr;
    int         *temp;

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    modify_array(arr, 0, size);
    temp = (int *)realloc(arr, larger_size * sizeof(int));

    if(temp == NULL)
    {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr);
        return EXIT_FAILURE;
    }

    arr = temp;
    modify_array(arr, size, larger_size);
    print_array(arr, larger_size);
    free(arr);

    return EXIT_SUCCESS;
}

static void modify_array(int *arr, size_t start, size_t end)
{
    for(size_t i = start; i < end; i++)
    {
        arr[i] = (int)(i * 2);
    }
}

static void print_array(const int *arr, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
