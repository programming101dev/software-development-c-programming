#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(unsigned int i = 0; i < 10; i++)
    {
        if(i == 5)
        {
            continue;
        }

        printf("Iteration %u\n", i);
    }

    return EXIT_SUCCESS;
}
