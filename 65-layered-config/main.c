#include "arguments.h"
#include "config.h"
#include "defaults.h"
#include "env.h"
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <signal.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static atomic_int keep_running = 1;    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

static void handle_signal(int sig);
static void print_usage(const char *prog_name);
static void setup_signal_handling(void);
static void print_message(const char *message, int count, int delay);

int main(int argc, char *argv[])
{
    char *message = NULL;
    int  *count   = NULL;
    int  *delay   = NULL;

    // Handle command-line arguments
    int arg_result = handle_arguments(argc, argv, &message, &count, &delay);
    if(arg_result == 1)
    {
        print_usage(argv[0]);
        return EXIT_SUCCESS;
    }

    if(arg_result < 0)
    {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Handle environment variables, config file, and defaults
    handle_env(&message, &count, &delay);
    handle_config(&message, &count, &delay);
    handle_defaults(&message, &count, &delay);

    if(message == NULL)
    {
        fprintf(stderr, "Error: No message specified.\n");
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    setup_signal_handling();
    print_message(message, *count, *delay);

    free(message);
    return EXIT_SUCCESS;
}

static void handle_signal(int sig)
{
    if(sig == SIGINT)
    {
        atomic_store(&keep_running, 0);
    }
}

static void print_usage(const char *prog_name)
{
    fprintf(stderr, "Usage: %s [-n <count>] [-d <delay>] <message>\n", prog_name);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -h            Show this help message and exit\n");
    fprintf(stderr, "  -n <count>    Specify the number of times to print the message (default: %d, max: %d)\n", DEFAULT_COUNT, MAX_COUNT);
    fprintf(stderr, "  -d <delay>    Specify the delay in seconds between prints (default: %d, max: %d)\n", DEFAULT_DELAY, MAX_DELAY);
}

static void setup_signal_handling(void)
{
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags   = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

static void print_message(const char *message, int count, int delay)
{
    struct timespec req;
    req.tv_sec  = delay;
    req.tv_nsec = 0;

    for(int i = 0; i < count && atomic_load(&keep_running); ++i)
    {
        printf("%s\n", message);
        nanosleep(&req, NULL);
    }

    printf("Program terminated.\n");
}
