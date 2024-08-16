#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int numbers[5] = {1, 2, 3, 4, 5};

    printf("First element: %d\n", numbers[0]);
    printf("First element: %d\n", numbers[1]);
    printf("First element: %d\n", numbers[2]);
    printf("First element: %d\n", numbers[3]);
    printf("Third element: %d\n", numbers[4]);

    return EXIT_SUCCESS;
}
