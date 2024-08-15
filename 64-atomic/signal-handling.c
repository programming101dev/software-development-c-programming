#include <signal.h>
#include <stdatomic.h>
#include <stdio.h>
#include <unistd.h>

atomic_int signal_received = 0;

void handle_signal(int signal)
{
    atomic_store(&signal_received, signal);
}

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags   = 0;

    sigemptyset(&sa.sa_mask);
    if(sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("Error setting up signal handler");
        return 1;
    }

    while(1)
    {
        printf("Running...\n");
        sleep(1);
        if(atomic_load(&signal_received) == SIGINT)
        {
            printf("SIGINT received, exiting...\n");
            break;
        }
    }

    return 0;
}
