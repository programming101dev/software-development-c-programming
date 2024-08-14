#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <stdatomic.h>
#include <inttypes.h>
#include "config.h"

#define MAX_MESSAGE_LENGTH 256

static atomic_int keep_running = 1;

// Function prototypes
int main(int argc, char *argv[]);
static void handle_signal(int sig);
static void print_usage(const char *prog_name);
static void handle_arguments(int argc, char *argv[], char **message, int **count, int **delay);
static void handle_env(char **message, int **count, int **delay);
static void handle_config(char **message, int **count, int **delay);
static void handle_defaults(char **message, int **count, int **delay);
static void setup_signal_handling();
static void print_message(const char *message, int count, int delay);
static int convert_str_to_int(const char *str, int max_value, const char *source, const char *name);

int main(int argc, char *argv[]) {
    char *message = NULL;
    int *count = NULL;
    int *delay = NULL;

    handle_arguments(argc, argv, &message, &count, &delay);
    handle_env(&message, &count, &delay);
    handle_config(&message, &count, &delay);
    handle_defaults(&message, &count, &delay);

    if (message == NULL) {
        fprintf(stderr, "Error: No message specified.\n");
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    setup_signal_handling();
    print_message(message, *count, *delay);

    free(message);
    return EXIT_SUCCESS;
}

static void handle_signal(int sig) {
    if (sig == SIGINT) {
        atomic_store(&keep_running, 0);
    }
}

static void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s [-n <count>] [-d <delay>] <message>\n", prog_name);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -h,            Show this help message and exit\n");
    fprintf(stderr, "  -n <count>     Specify the number of times to print the message (default: %d, max: %d)\n", DEFAULT_COUNT, MAX_COUNT);
    fprintf(stderr, "  -d <delay>     Specify the delay in seconds between prints (default: %d, max: %d)\n", DEFAULT_DELAY, MAX_DELAY);
}

static void handle_defaults(char **message, int **count, int **delay) {
    static int default_count = DEFAULT_COUNT;
    static int default_delay = DEFAULT_DELAY;
    if (*count == NULL) *count = &default_count;
    if (*delay == NULL) *delay = &default_delay;
}

static void handle_config(char **message, int **count, int **delay) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MESSAGE=", 8) == 0 && *message == NULL) {
            *message = strdup(line + 8);
            (*message)[strcspn(*message, "\n")] = '\0';
        } else if (strncmp(line, "COUNT=", 6) == 0 && *count == NULL) {
            static int config_count;
            config_count = convert_str_to_int(line + 6, MAX_COUNT, "config file", "COUNT");
            *count = &config_count;
        } else if (strncmp(line, "DELAY=", 6) == 0 && *delay == NULL) {
            static int config_delay;
            config_delay = convert_str_to_int(line + 6, MAX_DELAY, "config file", "DELAY");
            *delay = &config_delay;
        }
    }

    fclose(file);
}

static void handle_env(char **message, int **count, int **delay) {
    char *env_message = getenv("MESSAGE");
    char *env_count = getenv("COUNT");
    char *env_delay = getenv("DELAY");

    if (env_message && *message == NULL) {
        *message = strdup(env_message);
    }
    if (env_count && *count == NULL) {
        static int env_count_val;
        env_count_val = convert_str_to_int(env_count, MAX_COUNT, "environment variable", "COUNT");
        *count = &env_count_val;
    }
    if (env_delay && *delay == NULL) {
        static int env_delay_val;
        env_delay_val = convert_str_to_int(env_delay, MAX_DELAY, "environment variable", "DELAY");
        *delay = &env_delay_val;
    }
}

static void handle_arguments(int argc, char *argv[], char **message, int **count, int **delay) {
    int opt;

    while ((opt = getopt(argc, argv, "hn:d:")) != -1) {
        switch (opt) {
            case 'h':
                print_usage(argv[0]);
                exit(EXIT_SUCCESS);
            case 'n':
                static int arg_count;
                arg_count = convert_str_to_int(optarg, MAX_COUNT, "command line", "COUNT");
                *count = &arg_count;
                break;
            case 'd':
                static int arg_delay;
                arg_delay = convert_str_to_int(optarg, MAX_DELAY, "command line", "DELAY");
                *delay = &arg_delay;
                break;
            default:
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (optind < argc) {
        if (*message == NULL) {
            *message = strdup(argv[optind]);
        } else {
            fprintf(stderr, "Error: Unknown arguments or message already specified.\n");
            print_usage(argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if (optind + 1 < argc) {
        fprintf(stderr, "Error: Too many arguments.\n");
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
}

static void setup_signal_handling() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

static void print_message(const char *message, int count, int delay) {
    for (int i = 0; i < count && atomic_load(&keep_running); ++i) {
        printf("%s\n", message);
        sleep(delay);
    }

    printf("Program terminated.\n");
}

static int convert_str_to_int(const char *str, int max_value, const char *source, const char *name) {
    char *endptr;
    errno = 0;
    uintmax_t value = strtoumax(str, &endptr, 10);

    if (errno != 0 || *endptr != '\0' || value > max_value) {
        fprintf(stderr, "Error: Invalid %s value '%s' from %s. Using default value.\n", name, str, source);
        return (name[0] == 'C') ? DEFAULT_COUNT : DEFAULT_DELAY;
    }

    return (int)value;
}
