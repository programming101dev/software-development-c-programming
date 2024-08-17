#include <stdio.h>
#include <stdlib.h>

static void some_function(int value);

int main(void)
{
    const int x = 10;

    printf("Before calling some_function, x = %d\n", x);
    some_function(x);
    printf("After calling some_function, x = %d\n", x);

    return EXIT_SUCCESS;
}

static void some_function(int value)
{
    printf("some_function called with value: %d\n", value);
}
