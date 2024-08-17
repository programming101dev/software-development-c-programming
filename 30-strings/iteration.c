#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char str[] = "Hello, World!";
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("Index %d: %c\n", i, str[i]);
    }

    return EXIT_SUCCESS;
}
