#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;

    number = 42;
    printf("Justification Specifiers Demonstration:\n");
    printf("Right-justify (default): %10d\n", number);
    printf("Left-justify: %-10d\n", number);

    return EXIT_SUCCESS;
}
