#include <stdio.h>
#include <stdlib.h>

#define INCREMENT(x) x + 1    // NOLINT(bugprone-macro-parentheses)

int main(void)
{
    const int y = 5;

    // Unexpected behaviour
    const int z = INCREMENT(y) + INCREMENT(y);

    // Output might be unexpected
    printf("y: %d, z: %d\n", y, z);

    return EXIT_SUCCESS;
}
