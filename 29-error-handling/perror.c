#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr;

    errno = 0;
    ptr   = malloc(sizeof(int) * 1000000000);

    if(ptr == NULL)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    free(ptr);

    return EXIT_SUCCESS;
}
