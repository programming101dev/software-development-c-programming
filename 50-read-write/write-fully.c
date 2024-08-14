#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

ssize_t write_fully(int fd, const void *buf, size_t count, int *err) {
    size_t bytes_written = 0;
    while (bytes_written < count) {
        ssize_t result = write(fd, (const char *)buf + bytes_written, count - bytes_written);
        if (result == -1) {
            if (errno == EINTR) {
                continue; // Interrupted, retry
            }
            *err = errno;
            return -1; // Error occurred
        }
        bytes_written += result;
    }
    return bytes_written;
}

int main(void) {
    const char *filename = "output.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    const char *message = "Hello, World! This is a test of the write_fully function.\n";
    int err = 0;
    ssize_t result = write_fully(fd, message, strlen(message), &err);
    if (result == -1) {
        perror("write_fully");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Written %zd bytes to %s\n", result, filename);

    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
