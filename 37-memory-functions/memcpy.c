#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int source[5]       = {1, 2, 3, 4, 5};
    int destination[10] = {0};

    memcpy(destination, source, sizeof(source));

    for(int i = 0; i < 10; i++)
    {
        printf("destination[%d] = %d\n", i, destination[i]);
    }

    return EXIT_SUCCESS;
}
