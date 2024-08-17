#include <stdio.h>
#include <stdlib.h>

static void some_function(int value);

int main(void)
{
    int x;

    x = 10;
    some_function(x);

    return EXIT_SUCCESS;
}

static void some_function(int value)
{
    printf("some_function called with value: %d\n", value);
}
