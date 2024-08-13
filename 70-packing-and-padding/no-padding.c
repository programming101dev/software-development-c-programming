#include <stdio.h>

struct Example
{
    unint8_t a; 	// 1 byte
    uint32_t b; 	// 4 bytes
    unint8_t c; 	// 1 byte
};

int main(void)
{
    printf("Size of struct Example: %zu bytes\n",
sizeof(struct Example));

    return 0;
}
