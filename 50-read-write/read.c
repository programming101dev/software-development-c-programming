#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int read_from_fd(int fd, int *err);

static int read_from_fd(int fd, int *err)
{
    char    buffer[128];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);

    if(bytes_read == -1)
    {
        *err = errno;
        return -1;
    }

    buffer[bytes_read] = '\0';
    printf("Read: %s\n", buffer);
    return 0;
}

int main(void)
{
    int fd  = open("example.txt", O_RDONLY);
    int err = 0;
    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    if(read_from_fd(fd, &err) == -1)
    {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    if(close(fd) == -1)
    {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
