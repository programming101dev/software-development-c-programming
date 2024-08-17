#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int increment(int value);

int main(void)
{
    const int original = 5;
    int       incremented;

    incremented = increment(original);
    printf("Incremented value: %d\n", incremented);

    return EXIT_SUCCESS;
}

static int increment(int value)
{
    const int result = value + 1;

    // Postcondition
    assert(result > value && "Result should be greater than the input value");

    return result;
}
