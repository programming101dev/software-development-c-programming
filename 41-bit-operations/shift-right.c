#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a      = 12;    // 1100 in binary
    unsigned int result = a >> (unsigned int)2;    // 0011 in binary

    printf("Bitwise Shift Right: %u\n", result);    // Output: 3

    return EXIT_SUCCESS;
}