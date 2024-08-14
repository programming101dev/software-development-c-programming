#include <stdlib.h>

void leak_in_condition(int condition);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-malloc-leak"
#endif

void leak_in_condition(int condition)
{
    if(condition)
    {
        const int *arr;

        // cppcheck-suppress unreadVariable
        // cppcheck-suppress unusedAllocatedMemory
        arr = (int *)malloc(5 * sizeof(int));    // NOLINT(clang-analyzer-deadcode.DeadStores)
        // cppcheck-suppress memleak
    }

    // Memory is not freed if condition is true
}    // NOLINT(clang-analyzer-unix.Malloc)

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

#pragma GCC diagnostic pop

int main(void)
{
    leak_in_condition(1);
    return EXIT_SUCCESS;
}
