#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x;

    x = 10;

    // cppcheck-suppress knownConditionTrueFalse
    if(x > 5)
    {
        int y;

        y = 20;

        printf("y = %d\n", y);
    }

    // printf("%d\n", y); // Error: y is not accessible here

    return EXIT_SUCCESS;
}
