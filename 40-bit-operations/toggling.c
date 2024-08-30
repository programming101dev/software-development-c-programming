#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const unsigned int toggle_mask = 0x00F0;
    unsigned int       value;

    value = 0xABCD;
    value ^= toggle_mask;
    printf("Value after toggling bits: %X\n", value);

    return EXIT_SUCCESS;
}
