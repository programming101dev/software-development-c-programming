#include "extern.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("sharedVar in file2.c before example() = %d\n", sharedVar);
    sharedVar += 5;    // Modify sharedVar directly in file2.c    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    example();    // Call example() to see the updated value
    printf("sharedVar in file2.c after example() = %d\n", sharedVar);

    return EXIT_SUCCESS;
}
