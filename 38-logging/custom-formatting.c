#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to log messages with custom formatting
void log_message(const char *level, const char *func, const char *message) {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character
    printf("[%s] [%s] [%s]: %s\n", timestamp, level, func, message);
}

void example_function() {
    log_message("INFO", __func__, "This is a message from example_function");
}

int main(void) {
    log_message("INFO", __func__, "Program started");
    example_function();
    log_message("ERROR", __func__, "An error occurred");
    log_message("DEBUG", __func__, "Debugging information");
    return EXIT_SUCCESS;
}
