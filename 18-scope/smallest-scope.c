#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    const int x = 10;

    if(x > 5)
    {
        const int y = 20;

        printf("y = %d\n", y);
    }
}

int main(void)
{
    example();
    return EXIT_SUCCESS;
}