#include <stdio.h>

static void add(int a, int b);
static void subtract(int a, int b);
static void operate(int a, int b, void (*operation)(int, int));

static void add(int a, int b)
{
    printf("Sum: %d\n", a + b);
}

static void subtract(int a, int b)
{
    printf("Difference: %d\n", a - b);
}

static void operate(int a, int b, void (*operation)(int, int))
{
    operation(a, b);
}

int main(void)
{
    operate(10, 5, add);
    operate(10, 5, subtract);
    return 0;
}
