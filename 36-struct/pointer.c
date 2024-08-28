#include <stdio.h>
#include <stdlib.h>

struct person
{
    const char *name;
    int         age;
    float       height;
};

int main(void)
{
    struct person  pat;
    struct person *p;

    p          = &pat;
    pat.name   = "Pat Doe";
    pat.age    = 42;
    pat.height = 5.9F;
    printf("Name: %s, Age: %d, Height: %.1f\n", pat.name, pat.age, (double)pat.height);
    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, (double)p->height);

    p->name   = "Chris Doe";
    p->age    = 24;
    p->height = 6.2F;
    printf("Name: %s, Age: %d, Height: %.1f\n", pat.name, pat.age, (double)pat.height);
    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, (double)p->height);

    return EXIT_SUCCESS;
}
