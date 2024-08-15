#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <stdlib.h>

// cppcheck-suppress constParameter
int main(int argc, char *argv[])
{
    int exit_status;

    if(argc == 0)
    {
        exit_status = EXIT_FAILURE;
    }
    else
    {
        exit_status = EXIT_SUCCESS;
    }

    return exit_status;
}

#pragma GCC diagnostic pop
