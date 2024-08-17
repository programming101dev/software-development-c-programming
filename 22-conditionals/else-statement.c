#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;

    number = -5;

    // cppcheck-suppress knownConditionTrueFalse
    if(number > 0)
    {
        printf("The number is positive.\n");
    }
    else
    {
        printf("The number is negative.\n");
    }

    return EXIT_SUCCESS;
}
