#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t;
    int    result;

    t = time(NULL);
    if(t == (time_t)-1)
    {
        perror("time");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    printf("Current time (epoch): %ld\n", t);
    result = EXIT_SUCCESS;

cleanup:
    return result;
}
