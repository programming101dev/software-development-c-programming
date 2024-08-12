#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const bool a     = true;    // Equivalent to _Bool a = 1;
    const bool b     = false;    // Equivalent to _Bool b = 0;
    const bool not_a = !a;
    const bool not_b = !b;

    printf("Result of !%d operation: %d\n", a, not_a);
    printf("Result of !%d operation: %d\n", b, not_b);

    return EXIT_SUCCESS;
}
