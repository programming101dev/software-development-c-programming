#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_LLONG (sizeof(long long) * 8 / 3 + 2)    // +1 for sign, +1 for null terminator

int main(void)
{
    long long num;
    char     *str;
    int       bytes;

    str = (char *)malloc(DIGITS_IN_LLONG * sizeof(char));
    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;
    }

    num   = LLONG_MAX;
    bytes = snprintf(str, DIGITS_IN_LLONG, "%lld", num);

    if((unsigned long)bytes >= DIGITS_IN_LLONG)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
