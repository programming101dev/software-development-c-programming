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

    original.name = strdup("Jane Doe");

    if(original.name == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for original name.\n");
        return EXIT_FAILURE;
    }

    original.age = 30;
    memcpy(&copy, &original, sizeof(struct person));
    printf("Before modification:\n");
    printf("Original: Name = %s, Age = %d\n", original.name, original.age);
    printf("Copy: Name = %s, Age = %d\n", copy.name, copy.age);
    strncpy(copy.name, "Pat Doe", strlen(copy.name));
    copy.name[strlen("Pat Doe")] = '\0';
    copy.age                     = 42;
    printf("\nAfter modification:\n");
    printf("Original: Name = %s, Age = %d\n", original.name, original.age);
    printf("Copy: Name = %s, Age = %d\n", copy.name, copy.age);
    free(original.name);

    return EXIT_SUCCESS;
}
