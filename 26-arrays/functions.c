#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], size_t size);

void printArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);  // Calculates the number of elements
    printArray(numbers, size);
    return EXIT_SUCCESS;
}
