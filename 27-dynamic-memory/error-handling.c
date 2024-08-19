#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t size = 5;
    int         *arr;
    int          exit_code;

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        exit_code = EXIT_SUCCESS;
    }

    if(arr)
    {
        free(arr);
    }

    return exit_code;
}
