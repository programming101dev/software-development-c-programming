#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    short       short_int;
    long        long_int;
    long long   long_long_int;
    long double long_double;

    short_int     = 42;
    long_int      = 1234567890L;
    long_long_int = 1234567890123456789LL;
    long_double   = 3.141592653589793238L;
    printf("Length Modifiers Demonstration:\n");
    printf("Short integer: %hd\n", short_int);
    printf("Long integer: %ld\n", long_int);
    printf("Long long integer: %lld\n", long_long_int);
    printf("Long double: %Lf\n", long_double);

    return EXIT_SUCCESS;
}
