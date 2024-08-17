#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int *ptr;

    errno = 0;
    ptr   = malloc(sizeof(int) * 1000000000);

    if(ptr == NULL)
    {
        char errbuf[256];

        strerror_r(errno, errbuf, sizeof(errbuf));
        printf("Error allocating memory: %s\n", errbuf);
    }
    else
    {
        free(ptr);
        ptr = NULL;
    }

    return EXIT_SUCCESS;
}
