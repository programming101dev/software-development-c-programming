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

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#endif
static void person_modify_value(struct person p)
{
    // cppcheck-suppress unreadVariable
    p.name = "Chris Doe";
    // cppcheck-suppress unreadVariable
    p.age = 24;
    // cppcheck-suppress unreadVariable
    p.height = 6.2F;
}
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic pop
#endif

static void person_print(struct person p)
{
    printf("Name: %s, Age: %d, Height: %.1f\n", p.name, p.age, (double)p.height);
}
