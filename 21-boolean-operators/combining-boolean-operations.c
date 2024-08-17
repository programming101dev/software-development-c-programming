#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  a;
    int  b;
    int  c;
    bool combined_result;

    a = 5;
    b = 10;
    c = -3;
    // cppcheck-suppress knownConditionTrueFalse
    combined_result = ((a > 0 && b > 0) || c < 0);
    printf("Result of combined operation: %d\n", combined_result);

    return EXIT_SUCCESS;
}
