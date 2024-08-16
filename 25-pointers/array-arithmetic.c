#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int  arr[] = {1, 2, 3, 4, 5};
    const int *p     = arr;

    for(int i = 0; i < 5; i++)
    {
        printf("Element %d: %d\n", i, *(p + i));
    }

    return EXIT_SUCCESS;
}
