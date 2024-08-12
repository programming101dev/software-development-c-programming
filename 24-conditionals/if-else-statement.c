#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int number = 0;

    // cppcheck-suppress knownConditionTrueFalse
    if(number > 0)
    {
        printf("The number is positive.\n");
    }
    // cppcheck-suppress knownConditionTrueFalse
    else if(number < 0)
    {
        printf("The number is negative.\n");
    }
    else
    {
        printf("The number is zero.\n");
    }

    return EXIT_SUCCESS;
}
