#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int i;

    i = 0;

    while(i < 10)
    {
        printf("Iteration %u\n", i);
        i++;
    }

    return EXIT_SUCCESS;
}
