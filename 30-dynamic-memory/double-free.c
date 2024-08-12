#include <stdlib.h>
int main(void) {
    int *arr = (int *)malloc(5 * sizeof(int));
    free(arr);
    free(arr);  // Double free, leads to undefined behaviour
    return 0;
}
