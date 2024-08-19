#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int *create_array(size_t size);
static void free_array(int *arr);

int main(void)
{
    const size_t size = 5;
    int         *arr;
    int          exit_code;

    arr = create_array(size);

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        for(size_t i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
        exit_code = EXIT_SUCCESS;
    }

    if(arr != NULL)
    {
        free_array(arr);
    }

    return exit_code;
}

static int *create_array(size_t size)
{
    int *arr;

    arr = (int *)malloc(size * sizeof(int));

    if(arr != NULL)
    {
        for(size_t i = 0; i < size; i++)
        {
            arr[i] = (int)i;
        }
    }

    return arr;
}

static void free_array(int *arr)
{
    free(arr);
}
