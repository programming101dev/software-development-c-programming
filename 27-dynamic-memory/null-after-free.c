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
        free(arr);
        arr = NULL;
        // printf("%d\n", arr[0]);    // Undefined behavior    // NOLINT(clang-analyzer-unix.Malloc)
        exit_code = EXIT_SUCCESS;
    }

    return exit_code;
}
