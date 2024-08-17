#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int *ptr;

    errno = 0;
    ptr   = malloc(sizeof(int) * 1000000000);    // Attempt to allocate a large block of memory

    if(ptr == NULL)
    {
        char errbuf[256];    // Buffer to hold the error message
        strerror_r(errno, errbuf, sizeof(errbuf));    // Retrieve the error message
        printf("Error allocating memory: %s\n", errbuf);
    }
    else
    {
        free(ptr);
    }

    return EXIT_SUCCESS;
}
