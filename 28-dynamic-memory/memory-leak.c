#include <stdlib.h>

void leak_memory(void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

void leak_memory(void)
{
    // cppcheck-suppress unusedAllocatedMemory
    // cppcheck-suppress unreadVariable
    const int *arr = (int *)malloc(5 * sizeof(int));    // NOLINT(clang-analyzer-deadcode.DeadStores)

    // Memory allocated by malloc is not freed, causing a memory leak

    // To avoid a memory leak, you should free the memory:
    // free(arr);
    // cppcheck-suppress memleak
}    // NOLINT(clang-analyzer-unix.Malloc)

#pragma GCC diagnostic pop

int main(void)
{
    leak_memory();

    // Optional: indicate that the program has finished executing.
    return EXIT_SUCCESS;
}
