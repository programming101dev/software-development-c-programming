#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int    width;
    int    precision;
    double number;

    width     = 10;
    precision = 4;
    number    = 3.141592653589793;
    printf("Dynamic Width and Precision Demonstration:\n");
    printf("%*.*f\n", width, precision, number);

    return EXIT_SUCCESS;
}
