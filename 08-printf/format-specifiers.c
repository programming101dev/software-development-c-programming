#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int          signedInt;
    unsigned int unsignedInt;
    float        floatNum;
    char         character;

    signedInt   = -42;
    unsignedInt = 42;
    floatNum    = 3.14159F;
    character   = 'A';
    printf("Format Specifiers Demonstration:\n");
    printf("Signed integer: %d\n", signedInt);
    printf("Unsigned integer: %u\n", unsignedInt);
    printf("Floating-point: %f\n", (double)floatNum);
    printf("Character: %c\n", character);
    printf("Octal: %o\n", unsignedInt);
    printf("Hexadecimal (lowercase): %x\n", unsignedInt);
    printf("Hexadecimal (uppercase): %X\n", unsignedInt);
    printf("Literal percent sign: %%\n");

    return EXIT_SUCCESS;
}
