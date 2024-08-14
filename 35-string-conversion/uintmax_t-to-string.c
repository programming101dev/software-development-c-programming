#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_UINTMAX ((size_t)ceil(log10(UINTMAX_MAX)) + 1)    // +1 for null terminator

int main(void)
{
    uintmax_t num = UINTMAX_MAX;
    char     *str = NULL;    // Initialize to NULL for safety
    int       bytes;

    // Allocate memory for the string
    str = (char *)malloc(DIGITS_IN_UINTMAX * sizeof(char));
    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    bytes = snprintf(str, DIGITS_IN_UINTMAX, "%" PRIuMAX, num);

    if((unsigned long)bytes >= DIGITS_IN_UINTMAX)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);    // Free allocated memory
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
