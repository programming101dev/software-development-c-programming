#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  a;
    int *p;

    a = 10;
    p = &a;
    printf("Address of a: %p\n", (void *)&a);
    printf("Value of p: %p\n", (void *)p);
    printf("Value of a: %d\n", a);
    printf("Value pointed to by p: %d\n", *p);
    a++;
    printf("After incrementing a:\n");
    printf("Value of a: %d\n", a);
    printf("Value pointed to by p: %d\n", *p);
    (*p)++;
    printf("After incrementing value pointed to by p:\n");
    printf("Value of a: %d\n", a);
    printf("Value pointed to by p: %d\n", *p);

    return EXIT_SUCCESS;
}
