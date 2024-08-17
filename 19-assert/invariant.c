#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static unsigned int count_elements(unsigned int size);

int main(void)
{
    unsigned int size;
    unsigned int total_count;

    size        = 5;
    total_count = count_elements(size);
    printf("Total number of elements: %u\n", total_count);

    return EXIT_SUCCESS;
}

static unsigned int count_elements(unsigned int size)
{
    unsigned int count;

    count = 0;

    for(unsigned int i = 0; i < size; i++)
    {
        // Invariant
        assert(i <= size && "Loop index 'i' is out of bounds; it must be between 0 and 'size'");
        count++;
    }

    return count;
}
