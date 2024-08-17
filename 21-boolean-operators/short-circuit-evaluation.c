#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  a;
    int  b;
    int  c;
    bool and_result;
    bool or_result;

    a = 5;
    b = 10;
    c = 0;

    // cppcheck-suppress knownConditionTrueFalse
    and_result = (a > 0 && b++ > 0);

    // cppcheck-suppress knownConditionTrueFalse
    or_result = (a < 0 || c++ > 0);
    printf("Result of AND operation: %d, b = %d\n", and_result, b);
    printf("Result of OR operation: %d, c = %d\n", or_result, c);

    return EXIT_SUCCESS;
}
