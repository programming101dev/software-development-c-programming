#include "extern.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("sharedVar in file2.c before example() = %d\n", sharedVar);
    sharedVar += 5;
    example();
    printf("sharedVar in file2.c after example() = %d\n", sharedVar);

    return EXIT_SUCCESS;
}
