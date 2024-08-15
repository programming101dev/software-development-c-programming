#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int value      = 0xABCD;    // 1010101111001101 in binary
    unsigned int toggleMask = 0x00F0;    // 0000000011110000 in binary

    value ^= toggleMask;    // Toggle the middle four bits
    printf("Value after toggling bits: %X\n", value);    // Output: AB3D

    return EXIT_SUCCESS;
}
