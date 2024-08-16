#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = (int *)malloc(5 * sizeof(int));
    int *temp;

    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for(int i = 0; i < 5; i++)
    {
        arr[i] = i * 2;
    }

    // Create a temporary pointer to handle the reallocation
    temp = (int *)realloc(arr, 10 * sizeof(int));    // Reallocate memory for 10 integers
    if(temp == NULL)
    {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr);    // Free the original memory to avoid a leak
        return EXIT_FAILURE;
    }

    arr = temp;    // Assign the reallocated memory back to arr

    for(int i = 5; i < 10; i++)
    {
        arr[i] = i * 2;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);
    return EXIT_SUCCESS;
}
