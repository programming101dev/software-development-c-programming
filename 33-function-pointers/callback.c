#include <stdio.h>
#include <stdlib.h>

typedef void (*callback_func)(int);

static void process_data(int data, callback_func callback);
static void print_result(int result);

int main(void)
{
    process_data(5, print_result);
    return EXIT_SUCCESS;
}

static void process_data(int data, callback_func callback)
{
    int result;

    result = data * 2;
    callback(result);
}

static void print_result(int result)
{
    printf("Processed result: %d\n", result);
}
