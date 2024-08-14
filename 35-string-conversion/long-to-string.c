#include <limits.h>
#include <math.h>
#include <stdio.h>

#define DIGITS_IN_LONG (ceil(log10(LONG_MAX)) + 2)    // +1 for sign, +1 for null terminator

int main(void)
{
    long num = 1234567890L;
    char str[DIGITS_IN_LONG];
    if(snprintf(str, sizeof(str), "%ld", num) >= sizeof(str))
    {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
