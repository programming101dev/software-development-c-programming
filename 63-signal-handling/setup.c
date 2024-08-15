#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void handle_signal(int signal);

static void handle_signal(int signal)
{
    printf("Received signal %d\n", signal);
}

int main(void)
{
    if(signal(SIGINT, handle_signal) == SIG_ERR)
    {
        perror("Error setting up signal handler");
        return 1;
    }

    while(1)
    {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}
