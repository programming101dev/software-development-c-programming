#include <inttypes.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_UINTMAX (sizeof(uintmax_t) * 8 / 3 + 1)    // +1 for null terminator

int main(void)
{
    uintmax_t num;
    char     *str;
    int       bytes;

    str = (char *)malloc(DIGITS_IN_UINTMAX * sizeof(char));

    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;
    }

    num   = UINTMAX_MAX;
    bytes = snprintf(str, DIGITS_IN_UINTMAX, "%" PRIuMAX, num);

    if((unsigned long)bytes >= DIGITS_IN_UINTMAX)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
