#include <stdio.h>
#include <stdlib.h>

struct person    // NOLINT(altera-struct-pack-align)
{
    const char *name;
    int         age;
    float       height;
};

int main(void)
{
    struct person pat;

    pat.name   = "Pat Doe";
    pat.age    = 42;
    pat.height = 5.9F;

    printf("Name: %s, Age: %d, Height: %.1f\n", pat.name, pat.age, (double)pat.height);

    return EXIT_SUCCESS;
}
