#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const unsigned int toggleMask = 0x00F0;
    unsigned int       value;

    value = 0xABCD;
    value ^= toggleMask;
    printf("Value after toggling bits: %X\n", value);

    return EXIT_SUCCESS;
}
