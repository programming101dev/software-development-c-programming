#include <stdio.h>
#include <stdlib.h>

int complex_function(void);

int complex_function(void)
{
    int *ptr1 = NULL;
    int *ptr2 = NULL;

    ptr1 = malloc(sizeof(int) * 100);

    if(ptr1 == NULL)
    {
        perror("Failed to allocate memory for ptr1");
        goto error_ptr1;
    }

    ptr2 = malloc(sizeof(int) * 200);
    if(ptr2 == NULL)
    {
        perror("Failed to allocate memory for ptr2");
        goto error_ptr2;
    }

    // Perform operations with ptr1 and ptr2

    free(ptr2);
error_ptr2:
    free(ptr1);
error_ptr1:
    return ptr1 == NULL || ptr2 == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}

int main(void)
{
    return complex_function();
}
