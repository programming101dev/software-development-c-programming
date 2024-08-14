#include <float.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_LONG_DOUBLE (LDBL_DIG + 6)    // +1 for sign, +1 for decimal point, +1 for 'e', +1 for sign of exponent, +2 for exponent digits

int main(void)
{
    long double num = 3.141592653589793238L;
    char       *str = NULL;    // Initialize to NULL for safety
    int         bytes;

    // Allocate memory for the string
    str = (char *)malloc(DIGITS_IN_LONG_DOUBLE * sizeof(char));
    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    bytes = snprintf(str, DIGITS_IN_LONG_DOUBLE, "%Le", num);

    if((unsigned long)bytes >= DIGITS_IN_LONG_DOUBLE)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);    // Free allocated memory
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
