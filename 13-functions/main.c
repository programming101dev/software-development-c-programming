#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void greet(void);
int add(int a, int b);
float average(float x, float y, float z);

int main(void)
{
    int sum;
    float avg;

    greet();
    sum = add(10, 5);                     // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    printf("Sum: %d\n", sum);
    avg = average(4.0F, 8.0F, 12.0F);    // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    printf("Average: %.2f\n", (double)avg);

    return EXIT_SUCCESS;
}

// Function definitions
void greet(void)
{
    printf("Hello!\n");
}

int add(int a, int b)
{
    return a + b;
}

float average(float x, float y, float z)
{
    return (x + y + z) / 3;
}
