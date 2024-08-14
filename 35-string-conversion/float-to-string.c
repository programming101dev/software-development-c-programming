#include <float.h>
#include <math.h>
#include <stdio.h>

#define DIGITS_IN_FLOAT (DECIMAL_DIG + 2)    // +1 for sign, +1 for null terminator

int main(void)
{
    float num = 3.14159f;
    char  str[DIGITS_IN_FLOAT];
    if(snprintf(str, sizeof(str), "%f", num) >= sizeof(str))
    {
        fprintf(stderr, "Buffer size is too small\n");
        return EXIT_FAILURE;
    }
    printf("String representation: %s\n", str);
    return 0;
}
