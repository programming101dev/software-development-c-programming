#include <limits.h>
#include <math.h>
#include <stdio.h>

#define DIGITS_IN_ULLONG (ceil(log10(ULLONG_MAX)) + 1)    // +1 for null terminator

int main(void)
{
    unsigned long long num = 18446744073709551615ULL;
    char               str[DIGITS_IN_ULLONG];
    if(snprintf(str, sizeof(str), "%llu", num) >= sizeof(str))
    {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
