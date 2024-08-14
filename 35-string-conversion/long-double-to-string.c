#include <float.h>
#include <math.h>
#include <stdio.h>

#define DIGITS_IN_LDOUBLE (DECIMAL_DIG + 2)    // +1 for sign, +1 for null terminator

int main(void)
{
    long double num = 1.61803398875L;
    char        str[DIGITS_IN_LDOUBLE];
    if(snprintf(str, sizeof(str), "%Lf", num) >= sizeof(str))
    {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
