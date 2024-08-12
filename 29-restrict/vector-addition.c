#include <stdio.h>

void vector_add(int *restrict a, const int *restrict b, const int *restrict c, size_t n) {
    for (size_t i = 0; i < n; i++) {
        a[i] = b[i] + c[i];
    }
}

int main(void) {
    int x[5] = {1, 2, 3, 4, 5};
    int y[5] = {5, 4, 3, 2, 1};
    int z[5];

    vector_add(z, x, y, 5);

    for (size_t i = 0; i < 5; i++) {
        printf("%d ", z[i]);
    }
    printf("\n");

    return 0;
}

