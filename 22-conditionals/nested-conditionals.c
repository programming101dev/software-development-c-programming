#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;

    number = 5;

    // cppcheck-suppress knownConditionTrueFalse
    if(number > 0)
    {
        char letter;

        letter = 'A';

        // cppcheck-suppress knownConditionTrueFalse
        if(letter == 'A')
        {
            printf("Positive number and letter A.\n");
        }
        else
        {
            printf("Positive number but not letter A.\n");
        }
    }
    else
    {
        printf("Number is negative.\n");
    }

    return EXIT_SUCCESS;
}
