#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    char *name;
    int   age;
};

static int deep_copy(struct person *dest, const struct person *src);

int main(void)
{
    struct person original;
    struct person copy;
    int           status;
    int result;
    char         *new_name;

    original.name = strdup("Pat Doe");

    if(original.name == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for original name.\n");
        status = EXIT_FAILURE;
        goto cleanup;
    }

    original.age = 30;
    result = deep_copy(&copy, &original);

    if(result != 0)
    {
        fprintf(stderr, "Failed to perform deep copy.\n");
        status = EXIT_FAILURE;
        goto cleanup_original;
    }

    new_name = strdup("Jane Doe");

    if(new_name == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new name.\n");
        status = EXIT_FAILURE;
        goto cleanup_copy;
    }

    free(copy.name);
    copy.name = new_name;
    copy.age  = 42;
    printf("Original: Name = %s, Age = %d\n", original.name, original.age);
    printf("Copy: Name = %s, Age = %d\n", copy.name, copy.age);
    status = EXIT_SUCCESS;

cleanup_copy:
    free(copy.name);

cleanup_original:
    free(original.name);

cleanup:
    return status;
}

static int deep_copy(struct person *dest, const struct person *src)
{
    char *temp_name;

    temp_name =  strdup(src->name);

    if(dest->name == NULL)
    {
        return -1;
    }

    dest->name = temp_name;
    dest->age = src->age;

    return 0;
}
