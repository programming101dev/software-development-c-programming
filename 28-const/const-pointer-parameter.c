#include <stdio.h>

void print_value(const int *value) {
    printf("%d\n", *value);
}

int main(void) {
    int num = 42;
    print_value(&num);
    return 0;
}
