#include <stdio.h>
#include <stdlib.h>

struct Person    // NOLINT(altera-struct-pack-align)
{
    const char *name;
    int         age;
    float       height;
};

void person_print(const struct Person *p);

void person_print(const struct Person *p)
{
    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, (double)p->height);
}

int main(void)
{
    // Dynamically allocate memory for a Person struct
    struct Person *pat;

    pat = malloc(sizeof(struct Person));

    if(pat == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Initialize the members of the struct
    pat->name   = "Pat Doe";
    pat->age    = 42;
    pat->height = 5.9F;

    // Print the contents of the struct
    person_print(pat);

    // Free the allocated memory
    free(pat);

    return EXIT_SUCCESS;
}
