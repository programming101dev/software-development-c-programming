#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *str = "18446744073709551615";
    char       *endptr;
    uintmax_t   val;

    errno = 0;    // To distinguish success/failure after call
    val   = strtoumax(str, &endptr, 10);

    // Check for various possible errors
    if((errno == ERANGE && val == UINTMAX_MAX) || (errno != 0 && val == 0))
    {
        perror("strtoumax");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    printf("strtoumax() returned %" PRIuMAX "\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
