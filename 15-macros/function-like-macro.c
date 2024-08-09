#include <stdio.h>
#include <stdlib.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    const int num = 5;

    printf("The square of %d is %d\n", num, SQUARE(num));
    printf("The maximum of %d and %d is %d\n", num, 10,
MAX(num, 10));

    return EXIT_SUCCESS;
}
