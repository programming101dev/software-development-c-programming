#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int numbers[5] = {1, 2, 3, 4, 5};    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    for(int i = 0; i < 5; i++)    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    {    // Ensures index is within the valid range
        printf("Element %d: %d\n", i, numbers[i]);
    }
    return EXIT_SUCCESS;
}
