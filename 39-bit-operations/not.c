#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a;
    unsigned int result;

    a      = 12;
    result = ~a;
    printf("Bitwise NOT: %u\n", result);

    return EXIT_SUCCESS;
}
