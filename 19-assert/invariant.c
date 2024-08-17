#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int count_elements(int size);

int main(void)
{
    const int size = 5;
    int       total_count;

    total_count = count_elements(size);
    printf("Total number of elements: %d\n", total_count);

    return EXIT_SUCCESS;
}

static int count_elements(int size)
{
    int count;

    count = 0;

    for(int i = 0; i < size; i++)
    {
        // Invariant
        assert(i >= 0 && i <= size && "Loop index 'i' is out of bounds; it must be between 0 and 'size'");
        count++;
    }

    return count;
}
