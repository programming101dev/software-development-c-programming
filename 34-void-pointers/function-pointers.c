#include <stdio.h>
#include <stdlib.h>

typedef void (*process_func)(const void *);

static void process_data(const void *data, process_func func);
static void process_int(const void *data);
static void process_float(const void *data);
static void process_string(const void *data);

int main(void)
{
    int        num;
    float      f;
    const char str[] = "Hello";

    num = 10;
    f   = 3.14F;
    process_data(&num, process_int);
    process_data(&f, process_float);
    process_data(str, process_string);

    return EXIT_SUCCESS;
}

static void process_data(const void *data, process_func func)
{
    func(data);
}

static void process_int(const void *data)
{
    const int *int_data;

    int_data = (const int *)data;
    printf("Processing integer: %d\n", *int_data);
}

static void process_float(const void *data)
{
    const float *float_data;

    float_data = (const float *)data;
    printf("Processing float: %.2f\n", (double)*float_data);
}

static void process_string(const void *data)
{
    const char *str_data;

    str_data = (const char *)data;
    printf("Processing string: %s\n", str_data);
}
