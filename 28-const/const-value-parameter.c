#include <stdio.h>
void print_value(const int x) {
    printf("Value: %d\n", x);
    // x = 20;  // Error: x is read-only
}
int main(void) {
    const int x = 10;
    print_value(x);
    return 0;
}
