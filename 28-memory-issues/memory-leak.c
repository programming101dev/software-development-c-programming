#include <stddef.h>
#include <stdlib.h>

static void memory_leak(void);

int main(void)
{
    memory_leak();

    return EXIT_SUCCESS;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-malloc-leak"
#endif

static void memory_leak(void)
{
    const size_t size = 5;
    // cppcheck-suppress unusedAllocatedMemory
    // cppcheck-suppress unreadVariable
    const int *arr = (int *)malloc(size * sizeof(int));    // NOLINT(clang-analyzer-deadcode.DeadStores)
    // Memory allocated but not freed
    // cppcheck-suppress memleak
}    // NOLINT(clang-analyzer-unix.Malloc)
#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

#pragma GCC diagnostic pop
