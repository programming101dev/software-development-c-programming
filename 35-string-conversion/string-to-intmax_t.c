#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *str = "9223372036854775807";
    char       *endptr;
    intmax_t    val;

    errno = 0;    // To distinguish success/failure after call
    val   = strtoimax(str, &endptr, 10);

    // Check for various possible errors
    if((errno == ERANGE && (val == INTMAX_MAX || val == INTMAX_MIN)) || (errno != 0 && val == 0))
    {
        perror("strtoimax");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    printf("strtoimax() returned %" PRIdMAX "\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
