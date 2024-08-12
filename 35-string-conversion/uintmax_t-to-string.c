#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#define DIGITS_IN_UINTMAX (ceil(log10(UINTMAX_MAX)) + 1)  // +1 for null terminator

int main(void) {
    uintmax_t num = 18446744073709551615ULL;
    char str[DIGITS_IN_UINTMAX];
    if (snprintf(str, sizeof(str), "%" PRIuMAX, num) >= sizeof(str)) {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
