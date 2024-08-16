#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t size = 5;
    int   *arr  = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for(size_t i = 0; i < size; i++)
    {
        arr[i] = (int)i;
    }

    for(size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);

    return EXIT_SUCCESS;
}
