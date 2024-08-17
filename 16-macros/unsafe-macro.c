#include <stdio.h>
#include <stdlib.h>

#define INCREMENT(x) x + 1    // NOLINT(bugprone-macro-parentheses)

int main(void)
{
    int y;
    int z;

    y = 5;
    z = INCREMENT(y) + INCREMENT(y);
    printf("y: %d, z: %d\n", y, z);

    return EXIT_SUCCESS;
}
