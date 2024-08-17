#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_ULONG ((size_t)snprintf(NULL, 0, "%lu", (unsigned long)ULONG_MAX) + 1)

int main(void)
{
    unsigned long num;
    char         *str;
    size_t        bytes;

    str = (char *)malloc(DIGITS_IN_ULONG);

    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;
    }

    num   = ULONG_MAX;
    bytes = (size_t)snprintf(str, DIGITS_IN_ULONG, "%lu", num);

    if(bytes >= DIGITS_IN_ULONG)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
