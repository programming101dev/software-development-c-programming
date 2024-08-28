#include <stdio.h>
#include <stdlib.h>

struct person
{
    const char *name;
    int         age;
    float       height;
};

static void person_modify_pointer(struct person *p);
static void person_print(const struct person *p);

int main(void)
{
    struct person pat = {"Pat Doe", 42, 5.9F};

    printf("Before person_modify (by pointer):\n");
    person_print(&pat);
    person_modify_pointer(&pat);
    printf("After person_modify (by pointer):\n");
    person_print(&pat);

    return EXIT_SUCCESS;
}

static void person_modify_pointer(struct person *p)
{
    p->name   = "Chris Doe";
    p->age    = 24;
    p->height = 6.2F;
}

static void person_print(const struct person *p)
{
    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, (double)p->height);
}
