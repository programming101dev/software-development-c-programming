#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a;
    unsigned int result;

    a      = 12;
    result = a >> (unsigned int)2;
    printf("Bitwise Shift Right: %u\n", result);

    return EXIT_SUCCESS;
}
