#include <stdio.h>
#include <stdlib.h>
void buffer_overflow() {
    int arr[5];
    for (int i = 0; i <= 5; i++) {
        arr[i] = i;  // Buffer overflow on the last iteration
    }
}
int main(void) {
    buffer_overflow();
    return 0;
}
