#include <stdio.h>
#include <stdlib.h>

#define STRINGIFY(x) #x

int main(void)
{
    const char *str = STRINGIFY(Hello);

    printf("%s\n", str);    // Output: Hello, World!

    return EXIT_SUCCESS;
}
