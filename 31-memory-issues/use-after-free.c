#include <stdio.h>
#include <stdlib.h>

void use_after_free(void);

void use_after_free(void)
{
    int *arr = (int *)malloc(5 * sizeof(int));
    free(arr);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuse-after-free"

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-use-after-free"
#endif

    arr[0] = 10;    // Use-after-free error

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

#pragma GCC diagnostic pop
}

int main(void)
{
    use_after_free();
    return EXIT_SUCCESS;
}
