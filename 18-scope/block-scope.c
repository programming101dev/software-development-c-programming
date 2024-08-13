#include <stdio.h>
#include <stdlib.h>

void example(void);

void example(void)
{
    const int x = 10;    // Block scope within the function

    if(x > 5)    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    {
        const int y = 20;    // Block scope within the if statement
        printf("y = %d\n", y);    // y is accessible here
    }

    // printf("%d\n", y); // Error: y is not accessible here
}

int main(void)
{
    example();
    return EXIT_SUCCESS;
}