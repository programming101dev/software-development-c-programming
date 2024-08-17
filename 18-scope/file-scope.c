#include <stdio.h>
#include <stdlib.h>

static void example(void);

static int global_var = 100;    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

int main(void)
{
    printf("1) globalVar = %d\n", global_var);
    example();
    printf("3) globalVar = %d\n", global_var);

    return EXIT_SUCCESS;
}

static void example(void)
{
    printf("2) globalVar = %d\n", global_var);
    global_var++;
}
