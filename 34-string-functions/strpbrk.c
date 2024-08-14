#include <stdio.h>
#include <string.h>

int main(void)
{
    const char  str[]  = "Hello, World!";
    const char  keys[] = "oW";
    const char *ch     = strpbrk(str, keys);

    if(ch != NULL)
    {
        printf("First occurrence of any character in 'oW': %c\n", *ch);
    }
    else
    {
        printf("No characters found\n");
    }

    return 0;
}
