#include <stdio.h>
#include <stdlib.h>

int square(int x);

int main(void)
{
    int num;

    num = 5;
    printf("The square of %d is %d\n", num, square(num));

    return EXIT_SUCCESS;
}

inline int square(int x)
{
    return x * x;
}
