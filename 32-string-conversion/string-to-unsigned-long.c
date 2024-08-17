#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char   *str = "4294967295";
    char         *endptr;
    unsigned long val;

    errno = 0;    // To distinguish success/failure after call
    val   = strtoul(str, &endptr, 10);

    // Check for various possible errors
    if((errno == ERANGE && val == ULONG_MAX) || (errno != 0 && val == 0))
    {
        perror("strtoul");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    // If we got here, strtoul() successfully parsed a number
    printf("strtoul() returned %lu\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
