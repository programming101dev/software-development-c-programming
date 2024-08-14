#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

ssize_t read_fully(int fd, void *buf, size_t count, int *err) {
    size_t bytes_read = 0;
    while (bytes_read < count) {
        ssize_t result = read(fd, (char *)buf + bytes_read, count - bytes_read);
        if (result == 0) {
            break; // EOF reached
        }
        if (result == -1) {
            if (errno == EINTR) {
                continue; // Interrupted, retry
            }
            *err = errno;
            return -1; // Error occurred
        }
        bytes_read += result;
    }
    return bytes_read;
}

int main(void) {
    const char *filename = "example.txt";
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    char buffer[256];
    int err = 0;
    ssize_t result = read_fully(fd, buffer, sizeof(buffer) - 1, &err);
    if (result == -1) {
        perror("read_fully");
        close(fd);
        return EXIT_FAILURE;
    }

    buffer[result] = '\0'; // Null-terminate the buffer
    printf("Read %zd bytes: %s\n", result, buffer);

    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
