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
    printf("data as integer: %d\n", data.i);
    printf("data as float: %f\n", (double)data.f);
    printf("data as char: %c\n", data.c);

    data.c = 'A';
    printf("data as integer: %d\n", data.i);
    printf("data as float: %f\n", (double)data.f);
    printf("data as char: %c\n", data.c);

    data.i = 97;
    printf("data as integer: %d\n", data.i);
    printf("data as float: %f\n", (double)data.f);
    printf("data as char: %c\n", data.c);

    return EXIT_SUCCESS;
}
