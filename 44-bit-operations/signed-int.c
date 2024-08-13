#include <stdio.h>

int main(void) {
    int a = -12; // 11111111 11111111 11111111 11110100 in binary (32-bit)
    int result = a >> 2; // 11111111 11111111 11111111 11111101 in binary

    printf("Arithmetic Shift Right (Signed): %d\n", result); // Output: -3
    return 0;
}
