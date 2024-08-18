#include <stdio.h>
#include <stdlib.h>

typedef void (*operation_func)(int);

static void process_data(int data, operation_func operation);
static void log_result(int result);
static void alert_result(int result);

int main(void)
{
    int data = 5;

    process_data(data, log_result);
    process_data(data, alert_result);

    return EXIT_SUCCESS;
}

static void process_data(int data, operation_func operation)
{
    int result;

    result = data * 2;
    operation(result);
}

static void log_result(int result)
{
    printf("Logging result: %d\n", result);
}

static void alert_result(int result)
{
    printf("Alerting result: %d\n", result);
}
