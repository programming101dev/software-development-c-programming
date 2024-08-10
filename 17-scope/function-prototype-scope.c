#include <stdio.h>
#include <stdlib.h>

void example(int a); // 'a' has function prototype scope

void example(int a)
{
    printf("a = %d\n", a); // 'a' is accessible within the function definition
}

int main(void)
{
    const int x = 42;

    example(x);

    return EXIT_SUCCESS;
}
