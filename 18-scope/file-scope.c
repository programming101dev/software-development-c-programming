#include <stdio.h>
#include <stdlib.h>

void example(void);

const int globalVar = 100;    // File scope

void example(void)
{
    printf("globalVar = %d\n", globalVar);    // Accessible here
}

int main(void)
{
    example();

    return EXIT_SUCCESS;
}
