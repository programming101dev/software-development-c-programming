#include <stdio.h>

int* getPointerToLocal() {
    int localVar = 42;
    return &localVar;  // Returns address of local variable
}

int main(void) {
    int *p = getPointerToLocal();
    // p is now a dangling pointer because localVar is out of scope
    printf("Dangling pointer value: %d\n", *p);  // Undefined behavior
    return 0;
}
