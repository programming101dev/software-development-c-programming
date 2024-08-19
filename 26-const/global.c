#include <stdio.h>
#include <stdlib.h>

const int MAX_USERS = 100;

int main(void)
{
    printf("Max users: %d\n", MAX_USERS);
    // MAX_USERS = 200;  // Error: cannot modify a const global variable

    return EXIT_SUCCESS;
}
