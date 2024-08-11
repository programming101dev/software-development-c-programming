#include <stdio.h>
#include <stdlib.h>

static void someFunction(int value);

static void someFunction(int value)
{
    printf("someFunction called with value: %d\n", value);
}

int main(void)
{
    const int x = 10;
    someFunction(x);
    return EXIT_SUCCESS;
}
