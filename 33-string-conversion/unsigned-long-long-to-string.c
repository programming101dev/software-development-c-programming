#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Calculate the number of digits in ULLONG_MAX using snprintf and store as size_t
#define DIGITS_IN_ULLONG ((size_t)snprintf(NULL, 0, "%llu", (unsigned long long)ULLONG_MAX) + 1)

int main(void)
{
    unsigned long long num = ULLONG_MAX;
    char              *str = NULL;
    size_t             bytes;

    str = (char *)malloc(DIGITS_IN_ULLONG);
    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;
    }

    bytes = (size_t)snprintf(str, DIGITS_IN_ULLONG, "%llu", num);
    if(bytes >= DIGITS_IN_ULLONG)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
