#include <stddef.h>
#include <stdlib.h>

static void use_after_free(void);

int main(void)
{
    use_after_free();

    return EXIT_SUCCESS;
}

static void use_after_free(void)
{
    size_t size;
    int   *arr;

    size = 5;
    arr  = (int *)malloc(size * sizeof(int));
    free(arr);
#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wuse-after-free"
    #pragma GCC diagnostic ignored "-Wanalyzer-use-after-free"
#endif

    // cppcheck-suppress deallocuse
    arr[0] = 10;    // Use-after-free error    // NOLINT(clang-analyzer-unix.Malloc)

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif
}
