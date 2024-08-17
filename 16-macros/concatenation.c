#include <stdio.h>
#include <stdlib.h>

#define CONCAT(a, b) a##b

int main(void)
{
    int CONCAT(num, ber);

    number = 10;
    printf("%d\n", number);

    return EXIT_SUCCESS;
}
