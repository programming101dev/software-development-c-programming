#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to log messages with a timestamp
void log_message(const char *level, const char *message) {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character
    printf("[%s] [%s]: %s\n", timestamp, level, message);
}

int main(void) {
    log_message("INFO", "Program started");
    log_message("ERROR", "An error occurred");
    log_message("DEBUG", "Debugging information");
    return EXIT_SUCCESS;
}
