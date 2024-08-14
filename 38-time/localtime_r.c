#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t    t;
    struct tm tm_info;
    int       result;

    t = time(NULL);
    if(t == (time_t)-1)
    {
        perror("time");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    if(!localtime_r(&t, &tm_info))
    {
        perror("localtime_r");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    printf("Year: %d\n", tm_info.tm_year + 1900);
    printf("Month: %d\n", tm_info.tm_mon + 1);
    printf("Day: %d\n", tm_info.tm_mday);
    printf("Hour: %d\n", tm_info.tm_hour);
    printf("Minute: %d\n", tm_info.tm_min);
    printf("Second: %d\n", tm_info.tm_sec);

    result = EXIT_SUCCESS;

cleanup:
    return result;
}
