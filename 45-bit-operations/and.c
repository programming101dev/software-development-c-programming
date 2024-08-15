#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a      = 12;    // 1100 in binary
    unsigned int b      = 10;    // 1010 in binary
    unsigned int result = a & b;    // 1000 in binary

    printf("Bitwise AND: %u\n", result);    // Output: 8
    return EXIT_SUCCESS;
}
