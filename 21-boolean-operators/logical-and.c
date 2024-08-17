#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  a;
    int  b;
    bool result;

    a = 5;
    b = 10;
    // cppcheck-suppress knownConditionTrueFalse
    result = (a > 0 && b > 0);
    printf("Result of %d && %d operation: %d\n", a, b, result);

    return EXIT_SUCCESS;
}
