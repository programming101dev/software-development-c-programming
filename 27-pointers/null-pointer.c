#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL;    // Null pointer

    if(p == NULL)
    {
        printf("Pointer is null and cannot be dereferenced.\n");
    }
    else
    {
        printf("Pointer value: %d\n", *p);
    }
    return EXIT_SUCCESS;
}
