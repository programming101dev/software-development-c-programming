#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int value;
    unsigned int mask;
    unsigned int result;

    value  = 0xABCD;
    mask   = 0x00FF;
    result = value & mask;
    printf("Masked value: %X\n", result);

    return EXIT_SUCCESS;
}
