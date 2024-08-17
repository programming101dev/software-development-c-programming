#include <stdio.h>
#include <stdlib.h>

#define STRINGIFY(x) #x

int main(void)
{
    printf("%s\n", STRINGIFY(Hello));

    return EXIT_SUCCESS;
}
