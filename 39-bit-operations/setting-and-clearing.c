#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const unsigned int setMask   = 0x0001;
    const unsigned int clearMask = 0xFFFE;
    unsigned int       value;

    value = 0xABCD;
    value |= setMask;
    printf("Value after setting LSB: %X\n", value);

    value &= clearMask;
    printf("Value after clearing LSB: %X\n", value);

    return EXIT_SUCCESS;
}
