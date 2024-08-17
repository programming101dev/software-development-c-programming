#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char  str[] = "Hello, World!";
    const char *ch2   = strrchr(str, 'o');

    if(ch2 != NULL)
    {
        printf("Last occurrence of 'o': %c\n", *ch2);
    }
    else
    {
        printf("Character not found\n");
    }

    return EXIT_SUCCESS;
}
