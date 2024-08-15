#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a      = 12;    // 1100 in binary
    unsigned int b      = 10;    // 1010 in binary
    unsigned int result = a | b;    // 1110 in binary

    printf("Bitwise OR: %u\n", result);    // Output: 14

    return EXIT_SUCCESS;
}
