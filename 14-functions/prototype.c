#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);

int main(void)
{
    int result;

    result = add(2, 3);
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
    ;
}

int add(int a, int b)
{
    return a + b;
}
