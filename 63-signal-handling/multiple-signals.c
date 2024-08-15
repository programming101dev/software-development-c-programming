#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void handle_signal(int signal);

static void handle_signal(int signal)
{
    if(signal == SIGINT)
    {
        const char message[] = "Received SIGINT\n";
        write(STDOUT_FILENO, message, sizeof(message) - 1);
    }
    else if(signal == SIGTERM)
    {
        const char message[] = "Received SIGTERM\n";
        write(STDOUT_FILENO, message, sizeof(message) - 1);
    }
}

int main(void)
{
    struct sigaction sa;
    struct timespec  ts;

    // Set up the signal handler
    sa.sa_handler = handle_signal;
    sa.sa_flags   = 0;
    sigemptyset(&sa.sa_mask);

    if(sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("Error setting up SIGINT handler");
        return 1;
    }

    if(sigaction(SIGTERM, &sa, NULL) == -1)
    {
        perror("Error setting up SIGTERM handler");
        return 1;
    }

    ts.tv_sec  = 1;    // 1 second
    ts.tv_nsec = 0;    // 0 nanoseconds

    // Main loop
    while(1)
    {
        printf("Running...\n");

        // Replace sleep with nanosleep for thread safety
        if(nanosleep(&ts, NULL) == -1)
        {
            perror("nanosleep");
            return 1;
        }
    }

    return EXIT_SUCCESS;
}
