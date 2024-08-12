#include <stdio.h>
#include <stdlib.h>

#define SAFE_INCREMENT(x) ((x) + 1)

int main(void)
{
    const int y = 5;

    // Still needs caution
    const int z = SAFE_INCREMENT(y) + SAFE_INCREMENT(y);

    // More predictable behaviour
    printf("y: %d, z: %d\n", y, z);

    return EXIT_SUCCESS;
}
