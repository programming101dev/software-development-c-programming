#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// cppcheck-suppress constParameter
int main(int argc, char *argv[])
{
    int exit_code = EXIT_SUCCESS;

    if(argc < 2)
    {
        printf("Usage: %s num1 num2 ... numN\n", argv[0]);
        exit_code = EXIT_FAILURE;
    }
    else
    {
        int sum = 0;
        for(int i = 1; i < argc; i++)
        {
            char    *endptr;
            intmax_t val;

            errno = 0;    // Reset errno before the call
            val   = strtoimax(argv[i], &endptr, 10);

            // Check for various possible errors
            if((errno == ERANGE && (val == INTMAX_MAX || val == INTMAX_MIN)) || (errno != 0 && val == 0))
            {
                printf("Error: Out of range value detected: %s\n", argv[i]);
                exit_code = EXIT_FAILURE;
                break;
            }

            if(endptr == argv[i])
            {
                printf("Error: No digits were found in argument: %s\n", argv[i]);
                exit_code = EXIT_FAILURE;
                break;
            }

            // Check for characters after the number
            if(*endptr != '\0')
            {
                printf("Error: Non-numeric characters detected in argument: %s\n", argv[i]);
                exit_code = EXIT_FAILURE;
                break;
            }

            // Check if the value fits in an int
            if(val < INT_MIN || val > INT_MAX)
            {
                printf("Error: Value out of int range: %s\n", argv[i]);
                exit_code = EXIT_FAILURE;
                break;
            }

            sum += (int)val;
        }

        if(exit_code == EXIT_SUCCESS)
        {
            printf("Sum: %d\n", sum);
        }
    }

    return exit_code;
}
