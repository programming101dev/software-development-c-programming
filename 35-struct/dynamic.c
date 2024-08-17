#include <stdio.h>
#include <stdlib.h>

struct person    // NOLINT(altera-struct-pack-align)
{
    const char *name;
    int         age;
    float       height;
};

static void person_print(const struct person *p);

int main(void)
{
    struct person *pat;

    pat = malloc(sizeof(struct person));

    if(pat == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    pat->name   = "Pat Doe";
    pat->age    = 42;
    pat->height = 5.9F;
    person_print(pat);
    free(pat);
    pat = NULL;

    return EXIT_SUCCESS;
}

static void person_print(const struct person *p)
{
    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, (double)p->height);
}
