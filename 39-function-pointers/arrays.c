#include <stdio.h>

void add(int a, int b) {
    printf("Sum: %d\n", a + b);
}

void subtract(int a, int b) {
    printf("Difference: %d\n", a - b);
}

void multiply(int a, int b) {
    printf("Product: %d\n", a * b);
}

void divide(int a, int b) {
    if (b != 0) {
        printf("Quotient: %d\n", a / b);
    } else {
        printf("Cannot divide by zero\n");
    }
}

int main(void) {
    // Array of function pointers
    void (*operations[])(int, int) = { add, subtract, multiply, divide };

    int a = 20, b = 4;

    for (int i = 0; i < 4; i++) {
        operations[i](a, b);
    }

    return 0;
}
