#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const unsigned int set_mask   = 0x0001;
    const unsigned int clear_mask = 0xFFFE;
    unsigned int       value;

    value = 0xABCD;
    value |= set_mask;
    printf("Value after setting LSB: %X\n", value);

    value &= clear_mask;
    printf("Value after clearing LSB: %X\n", value);

    return EXIT_SUCCESS;
}
