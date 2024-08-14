#include <limits.h>
#include <math.h>
#include <stdio.h>

#define DIGITS_IN_UINT (ceil(log10(UINT_MAX)) + 1)    // +1 for null terminator

int main(void)
{
    unsigned int num = 4294967295U;
    char         str[DIGITS_IN_UINT];
    if(snprintf(str, sizeof(str), "%u", num) >= sizeof(str))
    {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
