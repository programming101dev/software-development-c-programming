#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal) {
    printf("Received signal %d\n", signal);
}

int main(void) {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;

    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting up SIGINT handler");
        return 1;
    }

    sigset_t block_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    if (sigprocmask(SIG_BLOCK, &block_set, NULL) == -1) {
        perror("Error blocking SIGINT");
        return 1;
    }

    printf("SIGINT blocked for 5 seconds\n");
    sleep(5);

    if (sigprocmask(SIG_UNBLOCK, &block_set, NULL) == -1) {
        perror("Error unblocking SIGINT");
        return 1;
    }

    printf("SIGINT unblocked\n");

    while (1) {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}
