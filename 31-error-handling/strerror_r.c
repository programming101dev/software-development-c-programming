#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int result;
    int exit_code;

    errno  = 0;
    result = fprintf(stdout, "%s", "Hello, World!");

    if(result < 0)
    {
        char error_message[256];

        strerror_r(errno, error_message, sizeof(error_message));
        fprintf(stderr, "Error occurred with fprintf: %s\n", error_message);
        exit_code = EXIT_FAILURE;
    }
    else
    {
        exit_code = EXIT_SUCCESS;
    }

    return exit_code;
}
