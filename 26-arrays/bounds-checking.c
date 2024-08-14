#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int numbers[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)
    {    // Ensures index is within the valid range
        printf("Element %d: %d\n", i, numbers[i]);
    }
    return EXIT_SUCCESS;
}
