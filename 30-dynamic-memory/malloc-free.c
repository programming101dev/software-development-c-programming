#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = (int *)malloc(5 * sizeof(int));    // Allocate memory for 5 integers
    if(arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    for(int i = 0; i < 5; i++)
    {
        arr[i] = i * 2;
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);    // Free the allocated memory
    return EXIT_SUCCESS;
}
