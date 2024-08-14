#include <stdio.h>

void copy_arrays(int * restrict dest, const int * restrict src, size_t n);

void copy_arrays(int * restrict dest, const int * restrict src, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

int main(void)
{
    const int a[5] = {1, 2, 3, 4, 5};
    int       b[5];

    copy_arrays(b, a, 5);

    for(size_t i = 0; i < 5; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}
