#include <stdio.h>
#include <stdlib.h>

union Data
{
    int   i;
    float f;
    char  c;
};

int main(void)
{
    union Data data;

    data.i = 97;
    printf("Data as integer: %d\n", data.i);
    printf("Data as float: %f\n", (double)data.f);
    printf("Data as char: %c\n", data.c);

    data.f = 3.14F;
    printf("Data as integer: %d\n", data.i);
    printf("Data as float: %f\n", (double)data.f);
    printf("Data as char: %c\n", data.c);

    data.c = 'A';
    printf("Data as integer: %d\n", data.i);
    printf("Data as float: %f\n", (double)data.f);
    printf("Data as char: %c\n", data.c);

    return EXIT_SUCCESS;
}
