#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int    numbers[5] = {1, 2, 3, 4, 5};
    const size_t size       = sizeof(numbers) / sizeof(numbers[0]);

    for(size_t i = 0; i < size; i++)
    {
        printf("Element %zu: %d\n", i, numbers[i]);
    }

    return EXIT_SUCCESS;
}
