#include "extern.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("sharedVar in file2.c before example() = %d\n", shared_var);
    shared_var += 5;
    example();
    printf("sharedVar in file2.c after example() = %d\n", shared_var);

    return EXIT_SUCCESS;
}
