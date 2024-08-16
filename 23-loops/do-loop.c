#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;
    do
    {
        printf("Iteration %d\n", i);
        i++;
    } while(i < 10);
    return EXIT_SUCCESS;
}
