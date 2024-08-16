#include <stdio.h>
#include <stdlib.h>

static void example(void);

static void example(void)
{
    static int x = 0;
    x++;
    printf("x = %d\n", x);
}

int main(void)
{
    example();
    example();

    return EXIT_SUCCESS;
}
