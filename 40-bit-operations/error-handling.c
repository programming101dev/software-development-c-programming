#include <stdio.h>
#include <stdlib.h>

#define INT_WIDTH (sizeof(int) * 8)    // Number of bits in an int

int main(void)
{
    unsigned int a          = 12;
    unsigned int shiftCount = 32;
    unsigned int result;

    if(shiftCount >= INT_WIDTH)
    {
        fprintf(stderr, "Shift count is too large\n");
        return EXIT_FAILURE;
    }

    result = a << shiftCount;
    printf("Result: %u\n", result);

    return EXIT_SUCCESS;
}
