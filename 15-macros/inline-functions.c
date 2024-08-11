#include <stdio.h>
#include <stdlib.h>

static inline int square(int x)
{
    return x * x;
}

int main(void)
{
    const int num = 5;

    printf("The square of %d is %d\n", num, square(num));

    return EXIT_SUCCESS;
}
