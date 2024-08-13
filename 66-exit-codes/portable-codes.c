#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Program logic here

    if (/* success condition */) {
        return EXIT_SUCCESS;  // Program terminated successfully
    } else {
        fprintf(stderr, "An error occurred.\n");
        return EXIT_FAILURE;  // Program terminated with an error
    }
}
