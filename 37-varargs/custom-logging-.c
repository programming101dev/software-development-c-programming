#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// Custom logging function
void log_message(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int main(void)
{
    log_message("Logging a message: %s, %d, %f\n", "Hello", 42, 3.14);

    return EXIT_SUCCESS;
}
