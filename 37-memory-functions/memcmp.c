#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, C!";
    int         result;

    result = memcmp(str1, str2, 7);

    if(result == 0)
    {
        printf("The first 7 bytes are the same.\n");
    }
    else
    {
        printf("The first 7 bytes differ.\n");
    }

    return EXIT_SUCCESS;
}
