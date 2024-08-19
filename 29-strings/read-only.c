#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

int main(void)
{
    const char *str = "Hello, World!";

    printf("%s\n", str);

    // Attempting to modify the string would result in undefined behavior
    // str[0] = 'h';  // Uncommenting this line would likely cause a crash

    return EXIT_SUCCESS;
}

#pragma GCC diagnostic pop
