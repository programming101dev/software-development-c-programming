#include <stdio.h>

int main(void)
{
    int        a = 10;
    int        b = 20;
    const int *p = &a;
    printf("Value pointed to by p: %d\n", *p);
    // *p = 20;  // Error: cannot modify the value pointed to by p
    p = &b;    // Allowed: p can point to another location
    printf("Value pointed to by p: %d\n", *p);
    return 0;
}
