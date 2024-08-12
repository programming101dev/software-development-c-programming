#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *arr = (int *)calloc(5, sizeof(int));  // Allocate and zero-initialize memory for 5 integers
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);  // All elements are initialized to zero
    }
    printf("\n");
    free(arr);
    return EXIT_SUCCESS;
}
