#include <stdio.h>
#include <stdlib.h>

#define INT_WIDTH (sizeof(int) * 8)

int main(void)
{
    const unsigned int shift_count = INT_WIDTH + 1;
    unsigned int       a;
    unsigned int       result;

    if(shift_count >= INT_WIDTH)
    {
        fprintf(stderr, "Shift count is too large\n");
        return EXIT_FAILURE;
    }

    a = 12;
    // cppcheck-suppress shiftTooManyBits
    result = a << shift_count;
    printf("Result: %u\n", result);

    return EXIT_SUCCESS;
}
