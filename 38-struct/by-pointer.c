#include <stdio.h>
#include <stdlib.h>

struct Person    // NOLINT(altera-struct-pack-align)
{
    const char *name;
    int         age;
    float       height;
};

static void person_modify_pointer(struct Person *p);
static void person_print(const struct Person *p);

static void person_modify_pointer(struct Person *p)
{
    p->age++;
}

static void person_print(const struct Person *p)
{
    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, (double)p->height);
}

int main(void)
{
    struct Person pat = {"Pat Doe", 42, 5.9F};

    printf("Before person_modify (by pointer):\n");
    person_print(&pat);
    person_modify_pointer(&pat);
    printf("After person_modify (by pointer):\n");
    person_print(&pat);

    return EXIT_SUCCESS;
}
