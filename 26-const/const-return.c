#include <stdio.h>
#include <stdlib.h>

static const char *get_message(void);

int main(void)
{
    const char *msg = get_message();

    printf("%s\n", msg);
    // msg[0] = 'h';  // Error: cannot modify the string literal

    return EXIT_SUCCESS;
}

static const char *get_message(void)
{
    return "Hello, World!";
}
