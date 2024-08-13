#include <stdio.h>

#define INT_WIDTH (sizeof(int) * 8) // Number of bits in an int

int main(void) {
    unsigned int a = 12;
    unsigned int shiftCount = 32;

    if (shiftCount >= INT_WIDTH) {
        fprintf(stderr, "Shift count is too large\n");
        return EXIT_FAILURE;
    }

    unsigned int result = a << shiftCount;
    printf("Result: %u\n", result);

    return 0;
}
