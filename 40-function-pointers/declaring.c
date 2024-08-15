#include <stdio.h>
#include <stdlib.h>

static void myFunction(int num);

int main(void)
{
    // Function pointer declaration
    void (*funcPtr)(int);

    // Assign the function pointer
    funcPtr = &myFunction;

    // Call the function using the pointer
    funcPtr(10);

    return EXIT_SUCCESS;
}

static void myFunction(int num)
{
    printf("Number: %d\n", num);
}
