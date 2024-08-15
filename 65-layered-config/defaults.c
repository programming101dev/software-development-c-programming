#include "defaults.h"
#include "config.h"
#include <stddef.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

void handle_defaults(char **message, int **count, int **delay)
{
    static int default_count = DEFAULT_COUNT;
    static int default_delay = DEFAULT_DELAY;

    if(*count == NULL)
    {
        *count = &default_count;
    }

    if(*delay == NULL)
    {
        *delay = &default_delay;
    }
}

#pragma GCC diagnostic pop
