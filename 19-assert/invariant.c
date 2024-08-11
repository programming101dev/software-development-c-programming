#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int count_elements(int arr[], int size);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
static int count_elements(int arr[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        // Invariant: i should always be less than or equal to size
        assert(i >= 0 && i <= size);
        count++;
    }

    return count;
}
#pragma GCC diagnostic pop

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};                // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    int size = sizeof(arr) / sizeof(arr[0]);

    int total_count = count_elements(arr, size);
    printf("Total number of elements: %d\n", total_count);

    return EXIT_SUCCESS;
}
