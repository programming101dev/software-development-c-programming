#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[10] = "Hello, C!";

    memset(str, '*', 5);
    printf("%s\n", str);

    return EXIT_SUCCESS;
}
