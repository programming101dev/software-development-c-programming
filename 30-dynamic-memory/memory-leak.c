#include <stdlib.h>
void leak_memory() {
    int *arr = (int *)malloc(5 * sizeof(int));
    // Memory allocated by malloc is not freed, causing a memory leak
}
