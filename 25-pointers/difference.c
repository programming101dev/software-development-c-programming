#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int  arr[] = {1, 2, 3, 4, 5};
    const int *p1;
    const int *p2;
    ptrdiff_t  diff;

    p1   = &arr[1];
    p2   = &arr[4];
    diff = p2 - p1;
    printf("Difference between p2 and p1: %td\n", diff);

    return EXIT_SUCCESS;
}
