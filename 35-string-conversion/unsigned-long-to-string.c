#include <stdio.h>
#include <limits.h>
#include <math.h>

#define DIGITS_IN_ULONG (ceil(log10(ULONG_MAX)) + 1)  // +1 for null terminator

int main(void) {
    unsigned long num = 4294967295UL;
    char str[DIGITS_IN_ULONG];
    if (snprintf(str, sizeof(str), "%lu", num) >= sizeof(str)) {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
