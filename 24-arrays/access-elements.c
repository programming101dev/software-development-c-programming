#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int numbers[5] = {1, 2, 3, 4, 5};
    printf("First element: %d\n", numbers[0]);    // Accesses the first element
    printf("Third element: %d\n", numbers[2]);    // Accesses the third element
    return EXIT_SUCCESS;
}
