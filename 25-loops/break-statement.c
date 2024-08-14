#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if(i == 5)
        {
            break;    // Exit the loop when i is 5
        }
        printf("Iteration %d\n", i);
    }
    return EXIT_SUCCESS;
}
