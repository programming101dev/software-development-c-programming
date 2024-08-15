#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// cppcheck-suppress constParameter
int main(int argc, char *argv[])
{
    int sum = 0;

    if(argc < 2)
    {
        printf("Usage: %s num1 num2 ... numN\n", argv[0]);
        return EXIT_FAILURE;
    }

    for(int i = 1; i < argc; i++)
    {
        char    *endptr;
        intmax_t val;

        errno = 0;    // Reset errno before the call
        val   = strtoimax(argv[i], &endptr, 10);

        // Check for various possible errors
        if(errno == ERANGE || val > INT_MAX || val < INT_MIN)
        {
            printf("Error: Out of range value detected: %s\n", argv[i]);
            return EXIT_FAILURE;
        }

        if(endptr == argv[i] || *endptr != '\0')
        {
            printf("Error: Non-numeric argument detected: %s\n", argv[i]);
            return EXIT_FAILURE;
        }

        sum += (int)val;
    }

    printf("Sum: %d\n", sum);
    return EXIT_SUCCESS;
}
