#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("File: %s\n", __FILE__);
    printf("Compiled on: %s\n", __DATE__);
    printf("Compiled at: %s\n", __TIME__);
    printf("Function: %s\n", __func__);
    printf("Line: %d\n", __LINE__);

#if __STDC__ == 1
    printf("Standard C\n");
#endif

#if defined(__STDC_VERSION__)
    printf("C Standard Version: %ld\n", (long)__STDC_VERSION__);    // NOLINT(google-readability-casting)
#else
    printf("__STDC_VERSION__ is not defined\n");
#endif

#if __STDC_HOSTED__ == 1
    printf("Hosted environment\n");
#else
    printf("Freestanding environment\n");
#endif

#if defined(_POSIX_C_SOURCE)
    printf("_POSIX_C_SOURCE: %d\n", (int)_POSIX_C_SOURCE);
#else
    printf("_POSIX_C_SOURCE is not defined\n");
#endif

#if defined(_XOPEN_SOURCE)
    printf("_XOPEN_SOURCE: %d\n", (int)_XOPEN_SOURCE);    // NOLINT(google-readability-casting)
#else
    printf("_XOPEN_SOURCE is not defined\n");
#endif

#if defined(_DARWIN_C_SOURCE)
    printf("_DARWIN_C_SOURCE is defined\n");
#else
    printf("_DARWIN_C_SOURCE is not defined\n");
#endif

#if defined(_DEFAULT_SOURCE)
    printf("_DEFAULT_SOURCE is defined\n");
#else
    printf("_DEFAULT_SOURCE is not defined\n");
#endif

#if defined(__BSD_VISIBLE)
    printf("__BSD_VISIBLE is defined\n");
#else
    printf("__BSD_VISIBLE is not defined\n");
#endif

    return EXIT_SUCCESS;
}
