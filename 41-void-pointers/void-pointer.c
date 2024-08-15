#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int         num   = 10;
    float       f     = 3.14F;
    char        str[] = "Hello";
    const void *ptr;

    ptr = &num;
    printf("Integer: %d\n", *(int *)ptr);

    ptr = &f;
    printf("Float: %.2f\n", (double)*(float *)ptr);

    ptr = str;
    printf("String: %s\n", (char *)ptr);

    return EXIT_SUCCESS;
}
