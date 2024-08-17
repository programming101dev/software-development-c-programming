#include <stddef.h>
#include <stdlib.h>

int main(void)
{
    const size_t size = 5;
    int         *arr;

    // cppcheck-suppress unusedAllocatedMemory
    arr = (int *)malloc(size * sizeof(int));
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
