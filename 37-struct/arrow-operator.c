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
    struct person  pat;
    struct person *p = &pat;

    p->name   = "Pat Doe";
    p->age    = 42;
    p->height = 5.9F;

    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, (double)p->height);
    printf("Name: %s, Age: %d, Height: %.1f\n", pat.name, pat.age, (double)pat.height);

    return EXIT_SUCCESS;
}
