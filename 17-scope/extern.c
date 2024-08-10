#include "extern.h"
#include <stdio.h>

int sharedVar = 0; // Definition of the extern variable // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

void example(void)
{
    sharedVar++;
    printf("sharedVar inside example() = %d\n", sharedVar);
}
