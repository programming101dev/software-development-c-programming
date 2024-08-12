#include <stdio.h>
#include <stdlib.h>

void printArray(int *p, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);  // Passes the array to the function
    return EXIT_SUCCESS;
}
