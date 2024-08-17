#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int         number;
    const char *result;

    number = 10;
    // cppcheck-suppress knownConditionTrueFalse
    result = (number > 0) ? "positive" : "negative";
    printf("The number is %s.\n", result);

    return EXIT_SUCCESS;
}
