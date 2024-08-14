#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_ULONG ((size_t)ceil(log10(ULONG_MAX)) + 1)    // +1 for null terminator

int main(void)
{
    unsigned long num = ULONG_MAX;
    char         *str = NULL;    // Initialize to NULL for safety
    int           bytes;

    // Allocate memory for the string
    str = (char *)malloc(DIGITS_IN_ULONG * sizeof(char));
    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    bytes = snprintf(str, DIGITS_IN_ULONG, "%lu", num);

    if((unsigned long)bytes >= DIGITS_IN_ULONG)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);    // Free allocated memory
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
