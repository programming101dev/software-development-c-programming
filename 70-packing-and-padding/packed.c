#include <stdio.h>
#include <stdint.h>

struct __attribute__((packed)) PackedExample
{
    unint8_t a; 	// 1 byte
    uint32_t b; 	// 4 bytes
    unint8_t c; 	// 1 byte
};

int main(void)
{
    printf("Size of struct PackedExample: %zu bytes\n",
sizeof(struct PackedExample));

    return 0;
}
