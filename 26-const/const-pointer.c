#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int        a;
    int        b;
    const int *p;

    a = 10;
    b = 20;
    p = &a;
    printf("Value pointed to by p: %d\n", *p);
    // *p = 20;  // Error: cannot modify the value pointed to by p
    p = &b;    // Allowed: p can point to another location
    printf("Value pointed to by p: %d\n", *p);

    return EXIT_SUCCESS;
}
