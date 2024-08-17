#include <stdio.h>
#include <stdlib.h>

struct person    // NOLINT(altera-struct-pack-align)
{
    const char *name;
    int         age;
    float       height;
};

static void person_modify_value(struct person p);
static void person_print(struct person p);

int main(void)
{
    struct person pat = {"Pat Doe", 42, 5.9F};

    printf("Before person_modify (by value):\n");
    person_print(pat);
    person_modify_value(pat);
    printf("After person_modify (by value):\n");
    person_print(pat);

    return EXIT_SUCCESS;
}

static void person_modify_value(struct person p)
{
    // cppcheck-suppress unreadVariable
    p.age++;
}

static void person_print(struct person p)
{
    printf("Name: %s, Age: %d, Height: %.1f\n", p.name, p.age, (double)p.height);
}