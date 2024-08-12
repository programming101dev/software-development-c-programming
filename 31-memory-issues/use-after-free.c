#include <stdio.h>
#include <stdlib.h>
void use_after_free() {
    int *arr = (int *)malloc(5 * sizeof(int));
    free(arr);
    arr[0] = 10;  // Use-after-free error
}
int main(void) {
    use_after_free();
    return 0;
}
