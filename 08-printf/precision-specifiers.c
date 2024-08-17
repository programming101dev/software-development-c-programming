#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double pi;

    pi = 3.141592653589793;
    printf("Precision Specifiers Demonstration:\n");
    printf("Pi to 2 decimal places: %.2f\n", pi);
    printf("Pi to 4 decimal places: %.4f\n", pi);

    return EXIT_SUCCESS;
}
