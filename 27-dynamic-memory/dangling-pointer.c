#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t size = 5;
    int         *arr;

    arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    free(arr);
    // arr is now a dangling pointer

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wuse-after-free"
#endif
    // cppcheck-suppress deallocuse
    printf("%d\n", arr[0]);    // Undefined behavior    // NOLINT(clang-analyzer-unix.Malloc)
#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

    return EXIT_SUCCESS;
}
