#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int               a;
    const int * const p = &a;

    a = 10;
    printf("Value pointed to by p: %d\n", *p);
    // *p = 20;  // Error: cannot modify the value pointed to by p
    // p = &b;  // Error: cannot change the address stored in p

    return EXIT_SUCCESS;
}
