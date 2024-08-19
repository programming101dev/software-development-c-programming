#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int process_array(size_t size);

int main(void)
{
    size_t size   = 5;
    int    status = process_array(size);

    return status;
}

static int process_array(size_t size)
{
    int *arr;
    int  status;

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        status = EXIT_FAILURE;
    }
    else
    {
        for(size_t i = 0; i < size; i++)
        {
            arr[i] = (int)i;
        }

        free(arr);
        status = EXIT_SUCCESS;
    }

    return status;
}
