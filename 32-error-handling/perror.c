#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof(int) * 1000000000);    // Attempt to allocate a large block of memory
    if(ptr == NULL)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    free(ptr);
    return EXIT_SUCCESS;
}
