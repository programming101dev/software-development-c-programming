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
        perror("Error occurred with fprintf");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        exit_code = EXIT_SUCCESS;
    }

    return exit_code;
}
