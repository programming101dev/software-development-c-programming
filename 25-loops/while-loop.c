#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;

    while(i < 10)    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    {
        printf("Iteration %d\n", i);
        i++;
    }
    return EXIT_SUCCESS;
}
