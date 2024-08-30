#include <stdio.h>
#include <stdlib.h>

void example(void);

int main(void)
{
    example();

    return EXIT_SUCCESS;
}

void example(void)
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
}
