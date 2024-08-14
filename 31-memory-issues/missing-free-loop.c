#include <stdlib.h>

void leak_in_loop(void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-malloc-leak"
#endif

void leak_in_loop(void)
{
    for(int i = 0; i < 10; i++)
    {
        // cppcheck-suppress unreadVariable
        // cppcheck-suppress unusedAllocatedMemory
        const int *arr = (int *)malloc(5 * sizeof(int));    // NOLINT(clang-analyzer-deadcode.DeadStores)
        // Memory allocated but not freed within the loop
    }
}
#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

#pragma GCC diagnostic pop

int main(void)
{
    leak_in_loop();
    return EXIT_SUCCESS;
}
