#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "ab:c")) != -1) {
        switch (opt) {
            case 'a':
                printf("Option -a\n");
            break;
            case 'b':
                printf("Option -b with value %s\n", optarg);
            break;
            case 'c':
                printf("Option -c\n");
            break;
            default:
                fprintf(stderr, "Usage: %s [-a] [-b value] [-c]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    return EXIT_SUCCESS;
}
