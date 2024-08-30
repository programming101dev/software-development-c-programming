#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char  str[] = "Hello, World!";
    const char *ch;

    ch = strrchr(str, 'o');

    if(ch != NULL)
    {
        printf("Last occurrence of 'o': %c\n", *ch);
    }
    else
    {
        printf("Character not found\n");
    }

    return EXIT_SUCCESS;
}
