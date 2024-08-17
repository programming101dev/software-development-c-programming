#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int *create_array(size_t size);

int main(void)
{
    const size_t size = 5;
    int         *arr;

    arr = create_array(size);

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for(size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);

    return EXIT_SUCCESS;
}

static int *create_array(size_t size)
{
    int *arr;

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < size; i++)
    {
        arr[i] = (int)i;
    }

    return arr;
}
