#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void someFunction(int value);

static void someFunction(int value)
{
    assert(value >= 0);
    printf("someFunction called with value: %d\n", value);
    // More code here
}

int main(void)
{
    const int x = 10;
    someFunction(x);
    return EXIT_SUCCESS;
}
