#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char        *str = "18446744073709551615";
    char              *endptr;
    unsigned long long val;

    errno = 0;    // To distinguish success/failure after call
    val   = strtoull(str, &endptr, 10);

    // Check for various possible errors
    if((errno == ERANGE && val == ULLONG_MAX) || (errno != 0 && val == 0))
    {
        perror("strtoull");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    // If we got here, strtoull() successfully parsed a number
    printf("strtoull() returned %llu\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
