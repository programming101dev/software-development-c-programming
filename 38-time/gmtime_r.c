#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t    t;
    struct tm tm_info;
    char      buf[80];
    int       result;
    size_t    strftime_result;

    t = time(NULL);
    if(t == (time_t)-1)
    {
        perror("time");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    if(!gmtime_r(&t, &tm_info))
    {
        perror("gmtime_r");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    strftime_result = strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm_info);
    if(strftime_result == 0)
    {
        perror("strftime");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    printf("Formatted UTC time: %s\n", buf);
    result = EXIT_SUCCESS;

cleanup:
    return result;
}
