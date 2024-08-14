#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char        str[] = "Hello, World! Welcome to C programming.";
    char       *saveptr;
    const char *token;
    bool        done = false;

    token = strtok_r(str, " ,.!", &saveptr);

    while(!done)
    {
        if(token == NULL)
        {
            done = true;
            continue;
        }

        printf("Token: %s\n", token);
        token = strtok_r(NULL, " ,.!", &saveptr);
    }

    return 0;
}
