#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int         num;
    float       f;
    const char  str[] = "Hello";
    const void *ptr;

    num = 10;
    f   = 3.14F;
    ptr = &num;
    printf("Integer: %d\n", *(int *)ptr);

    ptr = &f;
    printf("Float: %.2f\n", (double)*(float *)ptr);

    ptr = str;
    printf("String: %s\n", (char *)ptr);

    return EXIT_SUCCESS;
}
