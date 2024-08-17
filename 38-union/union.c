#include <stdio.h>
#include <stdlib.h>

union data
{
    float f;
    char  c;
    int   i;
};

int main(void)
{
    union data data;

    data.f = 3.14F;
    printf("Data as float: %.2f\n", (double)data.f);

    data.c = 'A';
    printf("Data as char: %c\n", data.c);

    data.i = 42;
    printf("Data as integer: %d\n", data.i);

    return EXIT_SUCCESS;
}
