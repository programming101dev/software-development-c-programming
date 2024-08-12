#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2;
    }
    arr = (int *)realloc(arr, 10 * sizeof(int));  // Reallocate memory for 10 integers
    if (arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return EXIT_FAILURE;
    }
    for (int i = 5; i < 10; i++) {
        arr[i] = i * 2;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return EXIT_SUCCESS;
}
