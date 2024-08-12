#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int    width     = 10;
    const int    precision = 4;
    const double number    = 3.141592653589793;

    printf("Dynamic Width and Precision Demonstration:\n");

    // Dynamic width and precision
    printf("%*.*f\n", width, precision, number);

    return EXIT_SUCCESS;
}
