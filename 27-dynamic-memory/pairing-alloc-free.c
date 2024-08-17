#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void process_array(size_t size);

int main(void)
{
    size_t size;

    size = 5;
    process_array(size);

    return EXIT_SUCCESS;
}

static void process_array(size_t size)
{
    int *arr;

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for(size_t i = 0; i < size; i++)
    {
        arr[i] = (int)i;
    }

    free(arr);
    arr = NULL;
}
