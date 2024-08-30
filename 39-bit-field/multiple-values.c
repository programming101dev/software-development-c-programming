#include <stdio.h>
#include <stdlib.h>

struct packed_data
{
    unsigned int a:4;    // 4 bits for a (values 0-15)
    unsigned int b:4;    // 4 bits for b (values 0-15)
    unsigned int c:8;    // 8 bits for c (values 0-255)
};

int main(void)
{
    struct packed_data data = {12, 9, 200};

    printf("Value of a: %u\n", data.a);
    printf("Value of b: %u\n", data.b);
    printf("Value of c: %u\n", data.c);

    data.a = 7;    // Modify field 'a'
    data.b = 14;    // Modify field 'b'

    printf("\nAfter modification:\n");
    printf("Value of a: %u\n", data.a);
    printf("Value of b: %u\n", data.b);
    printf("Value of c: %u\n", data.c);

    return EXIT_SUCCESS;
}
