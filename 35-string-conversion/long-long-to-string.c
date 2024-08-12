#include <stdio.h>
#include <limits.h>
#include <math.h>

#define DIGITS_IN_LLONG (ceil(log10(LLONG_MAX)) + 2)  // +1 for sign, +1 for null terminator

int main(void) {
    long long num = 9223372036854775807LL;
    char str[DIGITS_IN_LLONG];
    if (snprintf(str, sizeof(str), "%lld", num) >= sizeof(str)) {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
