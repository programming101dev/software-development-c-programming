#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char  str[]  = "Hello, World!";
    const char *substr = strstr(str, "World");

    if(substr != NULL)
    {
        printf("Found substring: %s\n", substr);
    }
    else
    {
        printf("Substring not found\n");
    }

    return EXIT_SUCCESS;
}
