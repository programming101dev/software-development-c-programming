#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a;
    unsigned int result;

    a      = 12;
    result = a >> (unsigned int)2;
    printf("Logical Shift Right (Unsigned): %u\n", result);    // Output: 3

    return EXIT_SUCCESS;
}
