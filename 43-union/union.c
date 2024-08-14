#include <stdio.h>

union Data
{
    int   i;
    float f;
    char  c;
};

int main(void)
{
    union Data data;

    data.i = 42;
    printf("Data as integer: %d\n", data.i);

    data.f = 3.14F;
    printf("Data as float: %.2f\n", (double)data.f);

    data.c = 'A';
    printf("Data as char: %c\n", data.c);

    return 0;
}
