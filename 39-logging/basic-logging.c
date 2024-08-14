#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void log_message(const char *level, const char *message);

static void log_message(const char *level, const char *message)
{
    time_t    now;
    struct tm timeinfo;
    char      timestamp[20];    // Buffer to hold the formatted timestamp

    time(&now);
    localtime_r(&now, &timeinfo);    // Thread-safe version of localtime
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &timeinfo);

    printf("[%s] [%s]: %s\n", timestamp, level, message);
}

int main(void)
{
    log_message("INFO", "Program started");
    log_message("ERROR", "An error occurred");
    log_message("DEBUG", "Debugging information");
    return EXIT_SUCCESS;
}
