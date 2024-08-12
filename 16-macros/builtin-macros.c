#include <stdio.h>
#include <stdlib.h>

#define LOG_ERROR(msg) fprintf(stderr, "%s (%s @ %s): %s\n", __func__, __DATE__, __TIME__, msg)

int main(void)
{
    LOG_ERROR("Something went wrong!");

    return EXIT_SUCCESS;
}
