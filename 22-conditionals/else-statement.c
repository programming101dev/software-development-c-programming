#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int number = -5;

    if(number > 0)
    {
        printf("The number is positive.\n");
    }
    else
    {
        printf("The number is not positive.\n");
    }

    return EXIT_SUCCESS;
}
