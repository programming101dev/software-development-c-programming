#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    printf("Element at [0][0]: %d\n", matrix[0][0]);    // Accesses the first element
    printf("Element at [1][2]: %d\n", matrix[1][2]);    // Accesses the element in the second row, third column
    return EXIT_SUCCESS;
}