#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    int b;
#pragma GCC diagnostic push
    int *p = &a;

    a = 10;
    // cppcheck-suppress unreadVariable
    b = 20;    // NOLINT(clang-analyzer-deadcode.DeadStores)
    printf("Value pointed to by p: %d\n", *p);
    *p = 20;    // Allowed: can modify the value pointed to by p
    // p = &b;  // Error: cannot change the address stored in p
    printf("Value of a: %d\n", a);

    return EXIT_SUCCESS;
}
