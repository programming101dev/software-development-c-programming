#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void handle_signal(int signal);

static void handle_signal(int signal)
{
    const char message[] = "Received SIGINT\n";
    if(signal == SIGINT)
    {
        write(STDOUT_FILENO, message, sizeof(message) - 1);
    }
}

int main(void)
{
    struct timespec ts;

    if(signal(SIGINT, handle_signal) == SIG_ERR)
    {
        perror("Error setting up signal handler");
        return 1;
    }

    ts.tv_sec  = 1;    // 1 second
    ts.tv_nsec = 0;    // 0 nanoseconds

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
