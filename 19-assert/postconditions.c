#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int increment(int value);

static int increment(int value)
{
    const int result = value + 1;
    assert(result > value && "Result should be greater than the input value");
    return result;
}

int main(void)
{
    const int original    = 5;
    int       incremented = increment(original);
    printf("Incremented value: %d\n", incremented);
    return EXIT_SUCCESS;
}
