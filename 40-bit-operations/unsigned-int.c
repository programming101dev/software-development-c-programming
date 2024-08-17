#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a      = 12;    // 00000000 00000000 00000000 00001100 in binary (32-bit)
    unsigned int result = a >> (unsigned int)2;    // 00000000 00000000 00000000 00000011 in binary

    printf("Logical Shift Right (Unsigned): %u\n", result);    // Output: 3

    return EXIT_SUCCESS;
}
