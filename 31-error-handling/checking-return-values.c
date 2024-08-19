#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int result;
    int exit_code;

    errno  = 0;
    result = fprintf(stdout, "%s", "Hello, World!");

    if(result < 0)
    {
        if(errno == EILSEQ)
        {
            fprintf(stderr, "Error: fprintf encountered an invalid wide-character sequence (errno: %d)\n", errno);
        }
        else if(errno == EOVERFLOW)
        {
            fprintf(stderr, "Error: fprintf output exceeds INT_MAX (errno: %d)\n", errno);
        }
        else if(errno == ENOMEM)
        {
            fprintf(stderr, "Error: Not enough memory to complete fprintf (errno: %d)\n", errno);
        }
        else
        {
            fprintf(stderr, "Error: An unknown error occurred with fprintf (errno: %d)\n", errno);
        }
        exit_code = EXIT_FAILURE;
    }
    else
    {
        exit_code = EXIT_SUCCESS;
    }

    return exit_code;
}
