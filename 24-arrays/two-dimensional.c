#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    printf("Element at [0][1]: %d\n", matrix[0][0]);
    printf("Element at [0][2]: %d\n", matrix[0][1]);
    printf("Element at [0][3]: %d\n", matrix[0][2]);
    printf("Element at [1][1]: %d\n", matrix[1][0]);
    printf("Element at [1][2]: %d\n", matrix[1][1]);
    printf("Element at [1][3]: %d\n", matrix[1][2]);
    printf("Element at [2][1]: %d\n", matrix[2][0]);
    printf("Element at [2][2]: %d\n", matrix[2][1]);
    printf("Element at [2][3]: %d\n", matrix[2][2]);

    return EXIT_SUCCESS;
}
