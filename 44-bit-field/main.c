#include <stdio.h>

struct Flags    // NOLINT(altera-struct-pack-align)
{
    unsigned int flag1:1;    // 1 bit
    unsigned int flag2:2;    // 2 bits
    unsigned int flag3:3;    // 3 bits
};

int main(void)
{
    struct Flags flags = {1, 3, 5};

    printf("flag1: %u\n", flags.flag1);
    printf("flag2: %u\n", flags.flag2);
    printf("flag3: %u\n", flags.flag3);

    return 0;
}
