#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void handle_signal(int signal);

static void handle_signal(int signal)
{
    if(signal == SIGINT)
    {
        printf("Received SIGINT\n");
    }
    else if(signal == SIGTERM)
    {
        printf("Received SIGTERM\n");
    }
}

int main(void)
{
    struct sigaction sa;
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

    while(1)
    {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}
