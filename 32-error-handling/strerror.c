#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void) {
    int *ptr = malloc(sizeof(int) * 1000000000);  // Attempt to allocate a large block of memory

    if (ptr == NULL) {
        printf("Error allocating memory: %s\n", strerror(errno));
    } else {
        free(ptr);
    }

    return 0;
}
