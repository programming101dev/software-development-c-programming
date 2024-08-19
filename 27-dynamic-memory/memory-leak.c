#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

int main(void)
{
    const size_t size = 5;
    const int   *arr;
    int          exit_code;

    arr = (int *)malloc(size * sizeof(int));    // NOLINT(clang-analyzer-deadcode.DeadStores)

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        // Memory allocated by malloc is not freed, causing a memory leak

        // To avoid a memory leak, you should free the memory:
        // free(arr);
        exit_code = EXIT_SUCCESS;    // NOLINT(clang-analyzer-unix.Malloc)
    }

    // cppcheck-suppress memleak
    return exit_code;
}

#pragma GCC diagnostic pop
