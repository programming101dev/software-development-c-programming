#include <stdio.h>
#include <stdlib.h>

struct file_permissions
{
    unsigned int read:1;
    unsigned int write:1;
    unsigned int execute:1;
};

int main(void)
{
    struct file_permissions perms = {1, 0, 1};    // Read and Execute permissions enabled

    printf("Read permission: %s\n", perms.read ? "Yes" : "No");
    printf("Write permission: %s\n", perms.write ? "Yes" : "No");
    printf("Execute permission: %s\n", perms.execute ? "Yes" : "No");

    perms.write = 1;    // Enable write permission
    printf("\nAfter enabling write permission:\n");
    // cppcheck-suppress knownConditionTrueFalse
    printf("Write permission: %s\n", perms.write ? "Yes" : "No");

    return EXIT_SUCCESS;
}
