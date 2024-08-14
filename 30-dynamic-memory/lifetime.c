#include <stdio.h>
#include <stdlib.h>

int *create_array(size_t size);

int *create_array(size_t size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    if(arr == NULL)
    {
        return NULL;    // Handle memory allocation failure
    }
    for(size_t i = 0; i < size; i++)
    {
        arr[i] = (int)i;
    }
    return arr;    // Return the pointer to the dynamically allocated array
}

int main(void)
{
    size_t size = 5;
    int   *arr  = create_array(size);
    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    for(size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return EXIT_SUCCESS;
}
