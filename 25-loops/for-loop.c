#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(int i = 0; i < 10; i++)    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    {
        printf("Iteration %d\n", i);
    }
    return EXIT_SUCCESS;
}
