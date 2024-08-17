#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(unsigned int i = 0; i < 3; i++)
    {
        for(unsigned int j = 0; j < 3; j++)
        {
            printf("i = %u, j = %u\n", i, j);
        }
    }

    return EXIT_SUCCESS;
}
