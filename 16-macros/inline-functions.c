#include <stdio.h>
#include <stdlib.h>

static int square(int x);

int main(void)
{
    int num;

    num = 5;
    printf("The square of %d is %d\n", num, square(num));

    return EXIT_SUCCESS;
}

static inline int square(int x)
{
    return x * x;
}
