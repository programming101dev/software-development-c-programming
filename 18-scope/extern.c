#include "extern.h"
#include <stdio.h>

int shared_var = 0;    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

void example(void)
{
    shared_var++;
    printf("sharedVar inside example() = %d\n", shared_var);
}
