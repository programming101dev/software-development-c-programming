#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int          signed_int;
    unsigned int unsigned_int;
    float        float_num;
    char         character;

    signed_int   = -42;
    unsigned_int = 42;
    float_num    = 3.14159F;
    character    = 'A';
    printf("Format Specifiers Demonstration:\n");
    printf("Signed integer: %d\n", signed_int);
    printf("Unsigned integer: %u\n", unsigned_int);
    printf("Floating-point: %f\n", (double)float_num);
    printf("Character: %c\n", character);
    printf("Octal: %o\n", unsigned_int);
    printf("Hexadecimal (lowercase): %x\n", unsigned_int);
    printf("Hexadecimal (uppercase): %X\n", unsigned_int);
    printf("Literal percent sign: %%\n");

    return EXIT_SUCCESS;
}
