#include <stdio.h>
#include <stdlib.h>

static void print_value(const int *value);

int main(void)
{
    const int num = 42;

    print_value(&num);

    return EXIT_SUCCESS;
}

static void print_value(const int *value)
{
    printf("%d\n", *value);
}
