#include <stdio.h>
#include <stdlib.h>

typedef void (*operation_func)(int, int);

static void add(int a, int b);
static void subtract(int a, int b);
static void multiply(int a, int b);
static void divide(int a, int b);

int main(void)
{
    operation_func operations[] = {add, subtract, multiply, divide};
    const size_t size            = sizeof(operations) / sizeof(operations[0]);

    for(size_t i = 0; i < size; i++)
    {
        int a = 20;
        int b = 4;
        operations[i](a, b);
    }

    return EXIT_SUCCESS;
}

static void add(int a, int b)
{
    printf("Sum: %d\n", a + b);
}

static void subtract(int a, int b)
{
    printf("Difference: %d\n", a - b);
}

static void multiply(int a, int b)
{
    printf("Product: %d\n", a * b);
}

static void divide(int a, int b)
{
    if(b != 0)
    {
        printf("Quotient: %d\n", a / b);
    }
    else
    {
        printf("Cannot divide by zero\n");
    }
}
