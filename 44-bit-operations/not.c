#include <stdio.h>

int main(void) {
    unsigned int a = 12; // 00000000 00000000 00000000 00001100 in binary
    unsigned int result = ~a; // 11111111 11111111 11111111 11110011 in binary

    printf("Bitwise NOT: %u\n", result); // Output: 4294967283 on a 32-bit system
    return 0;
}
