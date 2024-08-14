#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int fd;

    // Open a file for reading
    fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Redirect stdin to the file
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2");
        close(fd);
        return EXIT_FAILURE;
    }

    // Now stdin is redirected to the file
    char buffer[128];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        printf("Read from file: %s", buffer);
    } else {
        perror("fgets");
    }

    // Close the file descriptor
    close(fd);

    return EXIT_SUCCESS;
}
