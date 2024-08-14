#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(int i = 0; i < 10; i++)
    {
        if(i % 2 == 0)
        {
            printf("Even number: %d\n", i);
        }
        else
        {
            printf("Odd number: %d\n", i);
        }
    }
    return EXIT_SUCCESS;
}
