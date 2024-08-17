#include <stdio.h>
#include <stdlib.h>

static void print_value(const int *value);

static void print_value(const int *value)
{
    printf("%d\n", *value);
}

int main(void)
{
    int num;

    num = 42;
    print_value(&num);

    return EXIT_SUCCESS;
}
