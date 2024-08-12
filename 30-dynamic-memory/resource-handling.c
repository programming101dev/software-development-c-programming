#include <stdio.h>
#include <stdlib.h>
void cleanup(int *arr) {
    free(arr);
}
int main(void) {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    // Register cleanup function to ensure memory is freed
    atexit(cleanup(arr));
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2;
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Memory will be freed automatically at program exit
    return EXIT_SUCCESS;
}
