#include <stdio.h>

// Function pointer type for a function that takes a void pointer
typedef void (*ProcessFunc)(void *);

static void processData(void *data, ProcessFunc func);
static void processInt(void *data);
static void processFloat(void *data);
static void processString(void *data);

// Generic processing function
static void processData(void *data, ProcessFunc func)
{
    func(data);
}

// Callback function for processing an integer
static void processInt(void *data)
{
    const int *intData = (int *)data;
    printf("Processing integer: %d\n", *intData);
}

// Callback function for processing a float
static void processFloat(void *data)
{
    const float *floatData = (float *)data;
    printf("Processing float: %.2f\n", (double)*floatData);
}

// Callback function for processing a string
static void processString(void *data)
{
    const char *strData = (char *)data;
    printf("Processing string: %s\n", strData);
}

int main(void)
{
    int   num   = 10;
    float f     = 3.14F;
    char  str[] = "Hello";

    processData(&num, processInt);
    processData(&f, processFloat);
    processData(str, processString);

    return 0;
}
