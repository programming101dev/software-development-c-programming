#include <stdio.h>
#include <float.h>
#include <math.h>

#define DIGITS_IN_DOUBLE (DECIMAL_DIG + 2)  // +1 for sign, +1 for null terminator

int main(void) {
    double num = 2.718281828459;
    char str[DIGITS_IN_DOUBLE];
    if (snprintf(str, sizeof(str), "%f", num) >= sizeof(str)) {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
