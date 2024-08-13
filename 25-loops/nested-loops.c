#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("i = %d, j = %d\n", i, j);
        }
    }

    return EXIT_SUCCESS;
}
