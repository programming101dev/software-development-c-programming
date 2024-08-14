#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *str = "9223372036854775807";
    char       *endptr;
    long long   val;

    errno = 0;    // To distinguish success/failure after call
    val   = strtoll(str, &endptr, 10);

    // Check for various possible errors
    if((errno == ERANGE && (val == LLONG_MAX || val == LLONG_MIN)) || (errno != 0 && val == 0))
    {
        perror("strtoll");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    // If we got here, strtoll() successfully parsed a number
    printf("strtoll() returned %lld\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
