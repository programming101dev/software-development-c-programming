#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void log_message(const char *level, const char *func, const char *message);
static void example_function(void);

static void log_message(const char *level, const char *func, const char *message)
{
    time_t    now;
    struct tm timeinfo;
    char      timestamp[20];    // Buffer to hold the formatted timestamp

    time(&now);
    localtime_r(&now, &timeinfo);    // Thread-safe version of localtime
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &timeinfo);

    printf("[%s] [%s] [%s]: %s\n", timestamp, level, func, message);
}

static void example_function(void)
{
    log_message("INFO", __func__, "This is a message from example_function");
}

int main(void)
{
    log_message("INFO", __func__, "Program started");
    example_function();
    log_message("ERROR", __func__, "An error occurred");
    log_message("DEBUG", __func__, "Debugging information");
    return EXIT_SUCCESS;
}
