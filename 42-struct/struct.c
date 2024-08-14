#include <stdio.h>

struct Person    // NOLINT(altera-struct-pack-align)
{
    const char *name;
    int         age;
    float       height;
};

int main(void)
{
    struct Person pat;

    pat.name   = "Pat Doe";
    pat.age    = 42;
    pat.height = 5.9F;

    printf("Name: %s, Age: %d, Height: %.1f\n", pat.name, pat.age, (double)pat.height);

    return 0;
}
