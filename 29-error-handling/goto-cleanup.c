#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr1;
    int *ptr2;
    int  exit_code;

    errno = 0;
    ptr1  = malloc(sizeof(int) * 100);

    if(ptr1 == NULL)
    {
        perror("Failed to allocate memory for ptr1");
        exit_code = EXIT_FAILURE;
        goto done;
    }

    errno = 0;
    ptr2  = malloc(sizeof(int) * 200);

    if(ptr2 == NULL)
    {
        perror("Failed to allocate memory for ptr2");
        exit_code = EXIT_FAILURE;
        goto error_ptr2;
    }

    exit_code = EXIT_SUCCESS;

    free(ptr2);
    ptr2 = NULL;
error_ptr2:
    free(ptr1);
    ptr1 = NULL;
done:

    return exit_code;
}
