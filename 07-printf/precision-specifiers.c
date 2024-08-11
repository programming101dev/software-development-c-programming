#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const double pi       = 3.141592653589793;
    const char   string[] = "Hello, World!";

    printf("Precision Specifiers Demonstration:\n");

    // Floating-point number with precision
    printf("Pi to 2 decimal places: %.2f\n", pi);
    printf("Pi to 4 decimal places: %.4f\n", pi);

    // String with precision
    printf("First 5 characters of string: %.5s\n", string);

    return EXIT_SUCCESS;
}
