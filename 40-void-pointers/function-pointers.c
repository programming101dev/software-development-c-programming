#include <stdio.h>

// Function pointer type for a function that takes a void pointer
typedef void (*ProcessFunc)(void *);

// Generic processing function
void processData(void *data, ProcessFunc func) {
    func(data);
}

// Callback function for processing an integer
void processInt(void *data) {
    int *intData = (int *)data;
    printf("Processing integer: %d\n", *intData);
}

// Callback function for processing a float
void processFloat(void *data) {
    float *floatData = (float *)data;
    printf("Processing float: %.2f\n", *floatData);
}

// Callback function for processing a string
void processString(void *data) {
    char *strData = (char *)data;
    printf("Processing string: %s\n", strData);
}

int main(void) {
    int num = 10;
    float f = 3.14;
    char str[] = "Hello";

    processData(&num, processInt);
    processData(&f, processFloat);
    processData(str, processString);

    return 0;
}
