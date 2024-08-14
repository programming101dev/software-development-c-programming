#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int             arr[] = {1, 2, 3, 4, 5};
    const int      *p1    = &arr[1];    // Points to the second element
    const int      *p2    = &arr[4];    // Points to the fifth element
    const ptrdiff_t diff  = p2 - p1;    // Difference between p2 and p1

    printf("Difference between p2 and p1: %td\n", diff);

    return 0;
}
