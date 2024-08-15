#include <stdio.h>
#include <stdlib.h>

// cppcheck-suppress constParameter
int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);

    for(int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}
