#include <stdio.h>
#include <string.h>

int main(void)
{
    const char  str[] = "Hello, World!";
    const char *ch    = strchr(str, 'W');

    if(ch != NULL)
    {
        printf("First occurrence of 'W': %c\n", *ch);
    }
    else
    {
        printf("Character not found\n");
    }

    return 0;
}
