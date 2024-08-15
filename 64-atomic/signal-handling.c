#include <signal.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

atomic_int signal_received = 0;    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

static void handle_signal(int signal);

static void handle_signal(int signal)
{
    atomic_store(&signal_received, signal);
}

int main(void)
{
    struct sigaction sa;
    struct timespec  ts;

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

    while(1)
    {
        printf("Running...\n");

        // Replace sleep with nanosleep for thread safety
        if(nanosleep(&ts, NULL) == -1)
        {
            perror("Error during nanosleep");
            return 1;
        }

        if(atomic_load(&signal_received) == SIGINT)
        {
            printf("SIGINT received, exiting...\n");
            break;
        }
    }

    return EXIT_SUCCESS;
}
