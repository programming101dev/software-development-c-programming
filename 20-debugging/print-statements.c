#include <stdio.h>
#include <stdlib.h>

static void someFunction(int value);

static void someFunction(int value)
{
    printf("someFunction called with value: %d\n", value);
    // More code here
}

int main(void) {
    const int x = 10;
    printf("Before calling someFunction, x = %d\n", x);
    someFunction(x);
    printf("After calling someFunction, x = %d\n", x);
    return EXIT_SUCCESS;
}
