#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int   age  = 42;
    const char *name = "Pat";

    fprintf(stdout, "Name: %s, Age: %d\n", name, age);

    return EXIT_SUCCESS;
}
