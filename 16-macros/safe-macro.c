#include <stdio.h>
#include <stdlib.h>

#define SAFE_INCREMENT(x) ((x) + 1)

int main(void)
{
    int y;
    int z;

    y = 5;
    z = SAFE_INCREMENT(y) + SAFE_INCREMENT(y);
    printf("y: %d, z: %d\n", y, z);

    return EXIT_SUCCESS;
}
