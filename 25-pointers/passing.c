#include <stdio.h>
#include <stdlib.h>

static void increment_by_value(int n);
static void increment_by_pointer(int *p);

int main(void)
{
    int a;

    a = 10;

    increment_by_value(a);
    printf("After increment_by_value, a = %d\n", a);

    increment_by_pointer(&a);
    printf("After increment_by_pointer, a = %d\n", a);

    return EXIT_SUCCESS;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"

static void increment_by_value(int n)
{
    // cppcheck-suppress unreadVariable
    // cppcheck-suppress uselessAssignmentArg
    n++;
}

#pragma GCC diagnostic pop

static void increment_by_pointer(int *p)
{
    (*p)++;
}
