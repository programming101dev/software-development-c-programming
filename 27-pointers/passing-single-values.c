#include <stdio.h>
#include <stdlib.h>

void increment(int *p);

void increment(int *p)
{
    (*p)++;
}

int main(void)
{
    int a = 10;
    increment(&a);    // Passes the address of a to the function
    printf("Value of a: %d\n", a);    // a is modified to 11
    return EXIT_SUCCESS;
}
