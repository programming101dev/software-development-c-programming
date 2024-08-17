#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int i;

    i = 0;

    do
    {
        printf("Iteration %u\n", i);
        i++;
    } while(i < 10);

    return EXIT_SUCCESS;
}
