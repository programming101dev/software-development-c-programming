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

    some_function(x);

    return EXIT_SUCCESS;
}
