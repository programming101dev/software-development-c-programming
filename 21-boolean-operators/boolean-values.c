#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const bool a = true;    // Equivalent to _Bool a = 1;
    const bool b = false;    // Equivalent to _Bool b = 0;
    const bool c = 2;    // Equivalent to _Bool c = 2;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return EXIT_SUCCESS;
}
