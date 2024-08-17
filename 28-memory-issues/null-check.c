#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t size;
    int   *arr;

    size = 5;
    arr  = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    free(arr);
    arr = NULL;

    return EXIT_SUCCESS;
}
