#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    char *name;
    int   age;
};

int main(void)
{
    struct person original;
    struct person copy;

    original.name = strdup("Pat Doe");
    original.age  = 30;

    memcpy(&copy, &original, sizeof(struct person));
    strcpy(copy.name, "Jane Doe");
    printf("Original: Name = %s, Age = %d\n", original.name, original.age);
    printf("Copy: Name = %s, Age = %d\n", copy.name, copy.age);
    free(original.name);

    return EXIT_SUCCESS;
}
