#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int *global_arr = NULL;    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

static void cleanup(void);

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-use-after-free"
#endif

int main(void)
{
    int status;

    global_arr = (int *)malloc(5 * sizeof(int));

    if(global_arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        status = EXIT_FAILURE;
    }
    else
    {
        int result;

        result = atexit(cleanup);

        if(result == 0)
        {
            for(size_t i = 0; i < 5; i++)
            {
                global_arr[i] = (int)(i * 2);
                printf("%d ", global_arr[i]);
            }

            printf("\n");
            status = EXIT_SUCCESS;
        }
        else
        {
            fprintf(stderr, "Failed to register cleanup function\n");
            free(global_arr);
            status = EXIT_FAILURE;
        }
    }

    return status;
}

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

static void cleanup(void)
{
    free(global_arr);
}
