#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    while(true)    // This loop will run indefinitely
    {
        printf("This will print forever.\n");
    }

    return EXIT_SUCCESS;    // This line is never reached
}
