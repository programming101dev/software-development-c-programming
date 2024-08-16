#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *str = "1234567890";
    char       *endptr;
    long        val;

    errno = 0;    // To distinguish success/failure after call
    val   = strtol(str, &endptr, 10);

    // Check for various possible errors
    if((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (errno != 0 && val == 0))
    {
        perror("strtol");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    // If we got here, strtol() successfully parsed a number
    printf("strtol() returned %ld\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
