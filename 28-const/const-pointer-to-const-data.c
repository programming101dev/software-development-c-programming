#include <stdio.h>
int main(void) {
    int a = 10;
    const int * const p = &a;
    printf("Value pointed to by p: %d\n", *p);
    // *p = 20;  // Error: cannot modify the value pointed to by p
    // p = &b;  // Error: cannot change the address stored in p
    return 0;
}
