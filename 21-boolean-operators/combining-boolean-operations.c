#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int  a               = 5;
    const int  b               = 10;
    const int  c               = -3;
    const bool combined_result = ((a > 0 && b > 0) || c < 0);

    printf("Result of combined operation: %d\n", combined_result);

    return EXIT_SUCCESS;
}
