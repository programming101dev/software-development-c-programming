#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const short       shortInt    = 42;
    const long        longInt     = 1234567890L;
    const long long   longLongInt = 1234567890123456789LL;
    const long double longDouble  = 3.141592653589793238L;

    printf("Length Modifiers Demonstration:\n");
    printf("Short integer: %hd\n", shortInt);
    printf("Long integer: %ld\n", longInt);
    printf("Long long integer: %lld\n", longLongInt);
    printf("Long double: %Lf\n", longDouble);

    return EXIT_SUCCESS;
}
