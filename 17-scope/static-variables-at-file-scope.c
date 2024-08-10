#include <stdio.h>
#include <stdlib.h>

void example(void);

static int fileScopeVar = 0; // Static variable at file scope  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

void example(void)
{
    fileScopeVar++;
    printf("fileScopeVar = %d\n", fileScopeVar);
}

int main(void)
{
    example(); // Prints 1
    example(); // Prints 2
    return EXIT_SUCCESS;
}
