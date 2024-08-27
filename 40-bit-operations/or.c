#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a;
    unsigned int b;
    unsigned int result;

    a      = 12;
    b      = 10;
    result = a | b;
    printf("Bitwise OR: %u\n", result);

    return EXIT_SUCCESS;
}
