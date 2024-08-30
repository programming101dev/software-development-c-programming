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

    printf("setting data.f to 3.14\n");
    data.f = 3.14F;
    printf("data as integer: %d\n", data.i);
    printf("data as float: %f\n", (double)data.f);
    printf("data as char: %c\n", data.c);

    printf("\nsetting data.c to 'A'\n");
    data.c = 'A';
    printf("data as integer: %d\n", data.i);
    printf("data as float: %f\n", (double)data.f);
    printf("data as char: %c\n", data.c);

    printf("\nsetting data.i to 98\n");
    data.i = 98;
    printf("data as integer: %d\n", data.i);
    printf("data as float: %f\n", (double)data.f);
    printf("data as char: %c\n", data.c);

    return EXIT_SUCCESS;
}
