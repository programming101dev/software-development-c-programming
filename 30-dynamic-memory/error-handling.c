#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    // Use the allocated memory
    free(arr);
    return EXIT_SUCCESS;
}
