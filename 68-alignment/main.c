#include <stdio.h>
#include <stdalign.h>

struct NoAlignedExample {
    char a;
    char c;
};

struct AlignedExample {
    char a;
    _Alignas(4) int b;
    char c;
};

int main(void) {
    printf("Size of struct NoAlignedExample: %zu bytes\n", sizeof(struct NolignedExample));
    printf("Size of struct AlignedExample: %zu bytes\n", sizeof(struct AlignedExample));
    return 0;
}
