#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    const int x = 10;
    int       y;

    y = x + 5;    // Proper initialization  // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    printf("y = %d\n", y);
}

int main(void)
{
    example();
    return EXIT_SUCCESS;
}
