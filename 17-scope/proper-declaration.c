#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    const int x = 10;

    if (x > 5)     // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    {
        const int y = 20; // Declare y in the narrowest scope
        printf("y = %d\n", y);
    }
}

int main(void)
{
    example();
    return EXIT_SUCCESS;
}
