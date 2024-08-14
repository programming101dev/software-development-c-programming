#include <inttypes.h>
#include <math.h>
#include <stdio.h>

#define DIGITS_IN_INTMAX (ceil(log10(INTMAX_MAX)) + 2)    // +1 for sign, +1 for null terminator

int main(void)
{
    intmax_t num = 9223372036854775807;
    char     str[DIGITS_IN_INTMAX];
    if(snprintf(str, sizeof(str), "%" PRIdMAX, num) >= sizeof(str))
    {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
