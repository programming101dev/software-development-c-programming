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
        perror("Error setting up signal handler");
        return 1;
    }

    while (1) {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}
