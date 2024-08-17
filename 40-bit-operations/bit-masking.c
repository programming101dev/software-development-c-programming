#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int value  = 0xABCD;    // 1010101111001101 in binary
    unsigned int mask   = 0x00FF;    // 0000000011111111 in binary
    unsigned int result = value & mask;    // 0000000011001101 in binary

    printf("Masked value: %X\n", result);    // Output: CD

    return EXIT_SUCCESS;
}
