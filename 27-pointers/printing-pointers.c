#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  a = 10;
    int *p = &a;

    printf("Address of a: %p\n", (void *)&a);
    printf("Value of p: %p\n", (void *)p);
    printf("Value of a: %d\n", a);
    printf("Value pointed to by p: %d\n", *p);
    a++;
    printf("Value of a: %d\n", a);
    printf("Value pointed to by p: %d\n", *p);
    (*p)++;
    printf("Value of a: %d\n", a);
    printf("Value pointed to by p: %d\n", *p);

    return EXIT_SUCCESS;
}
