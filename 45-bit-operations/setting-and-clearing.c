#include <stdio.h>

int main(void)
{
    unsigned int value     = 0xABCD;    // 1010101111001101 in binary
    unsigned int setMask   = 0x0001;    // 0000000000000001 in binary
    unsigned int clearMask = 0xFFFE;    // 1111111111111110 in binary

    value |= setMask;    // Set the least significant bit
    printf("Value after setting LSB: %X\n", value);    // Output: ABCD

    value &= clearMask;    // Clear the least significant bit
    printf("Value after clearing LSB: %X\n", value);    // Output: ABCD

    return 0;
}
