#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void process_array(size_t size);

void process_array(size_t size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    for(size_t i = 0; i < size; i++)
    {
        arr[i] = (int)i;
    }
    // Process the array...
    free(arr);    // Ensure the memory is freed before the function exits
}

int main(void)
{
    process_array(5);
    return EXIT_SUCCESS;
}
