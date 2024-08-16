#include <stdio.h>
#include <stdlib.h>

static void some_function(int value);

static void some_function(int value)
{
    printf("someFunction called with value: %d\n", value);
}

int main(void)
{
    const int x = 10;

    printf("Before calling someFunction, x = %d\n", x);
    some_function(x);
    printf("After calling someFunction, x = %d\n", x);

    return EXIT_SUCCESS;
}
