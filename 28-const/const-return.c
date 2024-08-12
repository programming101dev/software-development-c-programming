#include <stdio.h>

const char* getMessage(void) {
    return "Hello, World!";
}
int main(void) {
    const char *msg = getMessage();
    printf("%s\n", msg);
    // msg[0] = 'h';  // Error: cannot modify the string literal
    return 0;
}
