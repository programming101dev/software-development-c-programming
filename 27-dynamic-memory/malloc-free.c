#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const size_t size = 5;
    int         *arr;

    arr = (int *)malloc(size * sizeof(int));

    for(size_t i = 0; i < size; i++)
    {
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-possible-null-dereference"
#endif
        arr[i] = (int)(i * 2);
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic pop
#endif
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);

    return EXIT_SUCCESS;
}
