#include <stdio.h>
#include <stdlib.h>
void memory_leak() {
    int *arr = (int *)malloc(5 * sizeof(int));
    // Memory allocated but not freed
}
int main(void) {
    memory_leak();
    return 0;
}
