#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t size = 5;
    int         *arr;

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    free(arr);
    arr = NULL;

    return EXIT_SUCCESS;
}