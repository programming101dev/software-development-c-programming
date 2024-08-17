#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    bool a;
    bool b;
    bool not_a;
    bool not_b;

    a     = true;
    b     = false;
    not_a = !a;
    not_b = !b;
    printf("Result of !%d operation: %d\n", a, not_a);
    printf("Result of !%d operation: %d\n", b, not_b);

    return EXIT_SUCCESS;
}
