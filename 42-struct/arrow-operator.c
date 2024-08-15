#include <stdio.h>
#include <stdlib.h>

struct Person    // NOLINT(altera-struct-pack-align)
{
    const char *name;
    int         age;
    float       height;
};

int main(void)
{
    struct Person  pat;
    struct Person *p = &pat;    // p is a pointer to john

    p->name   = "Pat Doe";
    p->age    = 42;
    p->height = 5.9F;

    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, (double)p->height);
    printf("Name: %s, Age: %d, Height: %.1f\n", pat.name, pat.age, (double)pat.height);

    return EXIT_SUCCESS;
}
