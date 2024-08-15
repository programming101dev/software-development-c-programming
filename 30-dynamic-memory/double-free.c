#include <stdlib.h>

int main(void)
{
    // cppcheck-suppress unusedAllocatedMemory
    int *arr = (int *)malloc(5 * sizeof(int));
    free(arr);

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wuse-after-free"
#endif
    // cppcheck-suppress doubleFree
    free(arr);    // Double free, leads to undefined behaviour    // NOLINT(clang-analyzer-unix.Malloc)
#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

    return EXIT_SUCCESS;
}
