#include <stdio.h>
#include <stdlib.h>

int *global_arr;    // Global variable to store the pointer    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

void cleanup(void);

void cleanup(void)
{
    free(global_arr);
}

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-use-after-free"
#endif

int main(void)
{
    global_arr = (int *)malloc(5 * sizeof(int));

    if(global_arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Register cleanup function to ensure memory is freed
    if(atexit(cleanup) != 0)
    {
        fprintf(stderr, "Failed to register cleanup function\n");
        free(global_arr);    // Clean up manually if atexit registration fails
        return EXIT_FAILURE;
    }

    for(int i = 0; i < 5; i++)
    {
        global_arr[i] = i * 2;
        printf("%d ", global_arr[i]);
    }

    printf("\n");
    // Memory will be freed automatically at program exit

    return EXIT_SUCCESS;
}

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif
