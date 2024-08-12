#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int  number = 5;
    const char letter = 'A';

    if(number > 0)
    {
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
        printf("Number is not positive.\n");
    }

    return EXIT_SUCCESS;
}
