#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int write_to_fd(int fd, const char *data, int *err);

static int write_to_fd(int fd, const char *data, int *err)
{
    ssize_t bytes_written = write(fd, data, strlen(data));

    if(bytes_written == -1)
    {
        *err = errno;
        return -1;
    }

    printf("Written: %s\n", data);

    return 0;
}

int main(void)
{
    int fd  = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    int err = 0;

    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    if(write_to_fd(fd, "Hello, World!\n", &err) == -1)
    {
        perror("write");
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
