#include <stdio.h>
#include <stdlib.h>

enum operation_type
{
    LOG,
    ALERT
};

static void process_data(int data, enum operation_type operation);
static void log_result(int result);
static void alert_result(int result);

int main(void)
{
    int data = 5;

    process_data(data, LOG);
    process_data(data, ALERT);

    return EXIT_SUCCESS;
}

static void process_data(int data, enum operation_type operation)
{
    int result;

    result = data * 2;

    if(operation == LOG)
    {
        log_result(result);
    }
    else if(operation == ALERT)
    {
        alert_result(result);
    }
    else
    {
        printf("Invalid operation\n");
    }
}

static void log_result(int result)
{
    printf("Logging result: %d\n", result);
}

static void alert_result(int result)
{
    printf("Alerting result: %d\n", result);
}
