#include <stdlib.h>

void memory_leak(void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-malloc-leak"
#endif

void memory_leak(void)
{
    int *arr = (int *)malloc(5 * sizeof(int));
    // Memory allocated but not freed
}
#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

#pragma GCC diagnostic pop

int main(void)
{
    memory_leak();

    return EXIT_SUCCESS;
}
