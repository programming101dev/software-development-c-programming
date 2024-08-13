#include <stdio.h>

// Function prototype
void myFunction(int);

// Function pointer declaration
void (*funcPtr)(int);

int main(void) {
    // Assign the function pointer
    funcPtr = &myFunction;

    // Call the function using the pointer
    funcPtr(10);

    return 0;
}

void myFunction(int num) {
    printf("Number: %d\n", num);
}
