#include <stdio.h>

static void myFunction(int num);

int main(void)
{
    // Function pointer declaration
    void (*funcPtr)(int);

    // Assign the function pointer
    funcPtr = &myFunction;

    // Call the function using the pointer
    funcPtr(10);

    return 0;
}

static void myFunction(int num)
{
    printf("Number: %d\n", num);
}
