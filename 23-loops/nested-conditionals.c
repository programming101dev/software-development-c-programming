#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(unsigned int i = 0; i < 10; i++)
    {
        if(i % 2 == 0)
        {
            printf("Even number: %u\n", i);
        }
        else
        {
            printf("Odd number: %u\n", i);
        }
    }

    return EXIT_SUCCESS;
}
