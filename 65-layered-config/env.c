#include "env.h"
#include "config.h"
#include <stdlib.h>
#include <string.h>

extern int string_to_int(const char * restrict str, int base, int *error);

void handle_env(char **message, int **count, int **delay)
{
    const char *env_message = getenv("MESSAGE");    // NOLINT(concurrency-mt-unsafe)
    const char *env_count   = getenv("COUNT");    // NOLINT(concurrency-mt-unsafe)
    const char *env_delay   = getenv("DELAY");    // NOLINT(concurrency-mt-unsafe)

    if(env_message && *message == NULL)
    {
        *message = strdup(env_message);
    }
    if(env_count && *count == NULL)
    {
        static int env_count_val;
        int        error = 0;
        env_count_val    = string_to_int(env_count, 10, &error);
        if(error || env_count_val > MAX_COUNT)
        {
            env_count_val = DEFAULT_COUNT;
        }
        *count = &env_count_val;
    }
    if(env_delay && *delay == NULL)
    {
        static int env_delay_val;
        int        error = 0;
        env_delay_val    = string_to_int(env_delay, 10, &error);
        if(error || env_delay_val > MAX_DELAY)
        {
            env_delay_val = DEFAULT_DELAY;
        }
        *delay = &env_delay_val;
    }
}
