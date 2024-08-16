#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int a = 5;
    int       b = 10;
    int       c = 0;

    // cppcheck-suppress knownConditionTrueFalse
    const bool and_result = (a > 0 && b++ > 0);

    // cppcheck-suppress knownConditionTrueFalse
    const bool or_result = (a < 0 || c++ > 0);

    printf("Result of AND operation: %d, b = %d\n", and_result, b);    // b is incremented to 11
    printf("Result of OR operation: %d, c = %d\n", or_result, c);    // c is incremented to 1

    return EXIT_SUCCESS;
}
