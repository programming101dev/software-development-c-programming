#include <stdio.h>

int main(void)
{
    int  a = 10;
    int *p = &a;

    printf("Address of a: %p\n", (void *)&a);
    printf("Value of p: %p\n", (void *)p);
    printf("Value pointed to by p: %d\n", *p);

    return 0;
}
