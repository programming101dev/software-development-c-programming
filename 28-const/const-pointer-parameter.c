#include <stdio.h>
#include <stdlib.h>

void print_value(const int *value);

void print_value(const int *value)
{
    printf("%d\n", *value);
}

int main(void)
{
    int num = 42;
    print_value(&num);

    return EXIT_SUCCESS;
}
