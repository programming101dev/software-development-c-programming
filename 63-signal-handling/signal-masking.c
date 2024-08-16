#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void handle_signal(int signal);

static void handle_signal(int signal)
{
    const char message[] = "Received signal ";
    char       buffer[30];
    int        length;

    length = snprintf(buffer, sizeof(buffer), "%s%d\n", message, signal);

    if(length > 0)
    {
        write(STDOUT_FILENO, buffer, (size_t)length);
    }
}

int main(void)
{
    struct sigaction sa;
    sigset_t         block_set;
    struct timespec  ts;

    sa.sa_handler = handle_signal;
    sa.sa_flags   = 0;

    sigemptyset(&sa.sa_mask);
    if(sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("Error setting up SIGINT handler");
        return 1;
    }

    sigemptyset(&block_set);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
    sigaddset(&block_set, SIGINT);
#pragma GCC diagnostic pop

    if(sigprocmask(SIG_BLOCK, &block_set, NULL) == -1)    // NOLINT(concurrency-mt-unsafe)
    {
        perror("Error blocking SIGINT");
        return 1;
    }

    printf("SIGINT blocked for 5 seconds\n");

    // Use nanosleep instead of sleep to make it thread-safe
    ts.tv_sec  = 5;
    ts.tv_nsec = 0;
    if(nanosleep(&ts, NULL) == -1)
    {
        perror("Error during nanosleep");
        return 1;
    }

    if(sigprocmask(SIG_UNBLOCK, &block_set, NULL) == -1)    // NOLINT(concurrency-mt-unsafe)
    {
        perror("Error unblocking SIGINT");
        return 1;
    }

    printf("SIGINT unblocked\n");

    ts.tv_sec  = 1;
    ts.tv_nsec = 0;

    while(1)
    {
        printf("Running...\n");

        if(nanosleep(&ts, NULL) == -1)
        {
            perror("Error during nanosleep");
            return 1;
        }
    }

    return EXIT_SUCCESS;
}
