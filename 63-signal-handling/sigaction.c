#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void handle_signal(int signal);

static void handle_signal(int signal)
{
    char message[50];
    int  length;

    length = snprintf(message, sizeof(message), "Received signal %d\n", signal);
    if(length > 0)
    {
        write(STDOUT_FILENO, message, (size_t)length);
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
        perror("Error setting up signal handler");
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
