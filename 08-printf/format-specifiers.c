#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int          signedInt   = -42;
    const unsigned int unsignedInt = 42;
    const float        floatNum    = 3.14159F;
    const char         character   = 'A';
    const char         string[]    = "Hello, World!";

    printf("Format Specifiers Demonstration:\n");
    printf("Signed integer: %d\n", signedInt);
    printf("Unsigned integer: %u\n", unsignedInt);
    printf("Floating-point: %f\n", (double)floatNum);
    printf("Character: %c\n", character);
    printf("String: %s\n", string);
    printf("Octal: %o\n", unsignedInt);
    printf("Hexadecimal (lowercase): %x\n", unsignedInt);
    printf("Hexadecimal (uppercase): %X\n", unsignedInt);
    printf("Literal percent sign: %%\n");

    return EXIT_SUCCESS;
}
