#include <stdio.h>
#include <stdlib.h>

// Define a callback type
typedef void (*Callback)(int);

static void processData(int data, Callback callback);
static void printResult(int result);

// Function that takes a callback
static void processData(int data, Callback callback)
{
    // Process the data (e.g., double it)
    int result = data * 2;
    // Call the callback with the result
    callback(result);
}

// Callback function
static void printResult(int result)
{
    printf("Processed result: %d\n", result);
}

int main(void)
{
    // Pass the callback function to processData
    processData(5, printResult);
    return EXIT_SUCCESS;
}
