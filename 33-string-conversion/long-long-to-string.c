#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_LLONG (sizeof(long long) * 8 / 3 + 2)    // +1 for sign, +1 for null terminator

int main(void)
{
    long long num = LLONG_MAX;
    char     *str = NULL;    // Initialize to NULL for safety
    int       bytes;

    // Allocate memory for the string
    str = (char *)malloc(DIGITS_IN_LLONG * sizeof(char));
    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    bytes = snprintf(str, DIGITS_IN_LLONG, "%lld", num);

    if((unsigned long)bytes >= DIGITS_IN_LLONG)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);    // Free allocated memory
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}