#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  arr[] = {1, 2, 3, 4, 5};
    int *p     = arr;

    for(int i = 0; i < 5; i++)
    {
        printf("Element %d: %d\n", i, *(p + i));    // Pointer arithmetic
    }
    return EXIT_SUCCESS;
}
