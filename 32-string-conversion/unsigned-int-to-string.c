#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_UINT ((size_t)ceil(log10(UINT_MAX)) + 1)    // +1 for null terminator

int main(void)
{
    unsigned int num;
    char        *str;
    int          bytes;

    str = (char *)malloc(DIGITS_IN_UINT * sizeof(char));

    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;
    }

    num   = UINT_MAX;
    bytes = snprintf(str, DIGITS_IN_UINT, "%u", num);

    if((unsigned long)bytes >= DIGITS_IN_UINT)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
