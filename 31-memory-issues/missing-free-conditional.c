#include <stdio.h>
#include <stdlib.h>
void leak_in_condition(int condition) {
    int *arr = NULL;
    if (condition) {
        arr = (int *)malloc(5 * sizeof(int));
    }
    // Memory is not freed if condition is true
}
int main(void) {
    leak_in_condition(1);
    return 0;
}
