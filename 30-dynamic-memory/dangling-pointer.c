#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    free(arr);
    // arr is now a dangling pointer
    printf("%d\n", arr[0]);  // Undefined behavior
    return EXIT_SUCCESS;
}
