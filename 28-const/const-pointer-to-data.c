#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 10;
    int b = 20;
    int * const p = &a;
    printf("Value pointed to by p: %d\n", *p);
    *p = 20;  // Allowed: can modify the value pointed to by p
    // p = &b;  // Error: cannot change the address stored in p
    printf("Value of a: %d\n", a);

    return EXIT_SUCCESS;
}
