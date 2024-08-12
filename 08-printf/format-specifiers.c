#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int          signedInt   = -42;
    const unsigned int unsignedInt = 42;
    const float        floatNum    = 3.14159F;
    const char         character   = 'A';
    const char         string[]    = "Hello, World!";
    const void        *pointer     = string;

    printf("Format Specifiers Demonstration:\n");

    // Signed decimal integer
    printf("Signed integer: %d\n", signedInt);

    // Unsigned decimal integer
    printf("Unsigned integer: %u\n", unsignedInt);

    // Floating-point number
    // the (double) is needed because of -Wdouble-promotion
    printf("Floating-point: %f\n", (double)floatNum);

    // Character
    printf("Character: %c\n", character);

    // String
    printf("String: %s\n", string);

    // Pointer
    printf("Pointer: %p\n", pointer);

    // Octal
    printf("Octal: %o\n", unsignedInt);

    // Hexadecimal (lowercase)
    printf("Hexadecimal (lowercase): %x\n", unsignedInt);

    // Hexadecimal (uppercase)
    printf("Hexadecimal (uppercase): %X\n", unsignedInt);

    // Literal percent sign
    printf("Literal percent sign: %%\n");

    return EXIT_SUCCESS;
}
