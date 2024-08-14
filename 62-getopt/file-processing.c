#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s -f input_file [-o output_file] [-v]\n", prog_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int opt;
    char *input_file = NULL;
    char *output_file = NULL;
    bool verbose = false;

    while ((opt = getopt(argc, argv, "f:o:v")) != -1) {
        switch (opt) {
            case 'f':
                input_file = optarg;
            break;
            case 'o':
                output_file = optarg;
            break;
            case 'v':
                verbose = true;
            break;
            default:
                print_usage(argv[0]);
        }
    }

    // Check for required arguments
    if (input_file == NULL) {
        fprintf(stderr, "Error: Input file is required\n");
        print_usage(argv[0]);
    }

    // Check for unexpected arguments
    if (optind < argc) {
        fprintf(stderr, "Error: Unexpected arguments\n");
        print_usage(argv[0]);
    }

    // Simulate file processing
    if (verbose) {
        printf("Verbose mode enabled\n");
    }
    printf("Processing input file: %s\n", input_file);
    if (output_file != NULL) {
        printf("Output will be saved to: %s\n", output_file);
    } else {
        printf("No output file specified, printing results to stdout\n");
    }

    // Here you would add the actual file processing logic

    return EXIT_SUCCESS;
}
