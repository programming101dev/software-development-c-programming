#include <float.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_IN_FLOAT (DECIMAL_DIG + 2)    // +1 for sign, +1 for null terminator

int main(void)
{
    float num;
    char *str;
    int   bytes;

    // Allocate memory for the string
    str = (char *)malloc(DIGITS_IN_FLOAT * sizeof(char));

    if(str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    num   = 3.14159F;
    bytes = snprintf(str, DIGITS_IN_FLOAT, "%f", (double)num);

    if((unsigned long)bytes >= DIGITS_IN_FLOAT)
    {
        fprintf(stderr, "Buffer size is too small\n");
        goto cleanup;    // Jump to cleanup to ensure memory is freed
    }

    printf("String representation: %s\n", str);

cleanup:
    free(str);
    return str == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}
