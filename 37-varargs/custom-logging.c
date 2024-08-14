#include <stdarg.h>
#include <stdio.h>

static void custom_log(const char *format, ...);

static void custom_log(const char *format, ...)
{
    va_list args;
    va_start(args, format);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    vprintf(format, args);    // Suppress the warning for this line
#pragma GCC diagnostic pop

    va_end(args);
}

int main(void)
{
    custom_log("This is a test: %d\n", 42);
    return 0;
}