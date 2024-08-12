#include <stdio.h>
#include <stdlib.h>
void leak_in_loop() {
    for (int i = 0; i < 10; i++) {
        int *arr = (int *)malloc(5 * sizeof(int));
        // Memory allocated but not freed within the loop
    }
}
int main(void) {
    leak_in_loop();
    return 0;
}
