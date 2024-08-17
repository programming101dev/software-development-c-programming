#include <stdio.h>
#include <stdlib.h>

struct flags    // NOLINT(altera-struct-pack-align)
{
    unsigned int flag1:1;
    unsigned int flag2:2;
    unsigned int flag3:3;
};

int main(void)
{
    struct flags flags = {1, 3, 5};

    printf("flag1: %u\n", flags.flag1);
    printf("flag2: %u\n", flags.flag2);
    printf("flag3: %u\n", flags.flag3);

    return EXIT_SUCCESS;
}
