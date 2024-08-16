#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int x = 10;

    if(x > 5)
    {
        const int y = 20;

        printf("y = %d\n", y);
    }

    // printf("%d\n", y); // Error: y is not accessible here

    return EXIT_SUCCESS;
}
