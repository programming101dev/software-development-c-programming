#include <stdio.h>

struct Person {
    char *name;
    int age;
    float height;
};

int main(void) {
    struct Person john;

    john.name = "John Doe";
    john.age = 30;
    john.height = 5.9;

    printf("Name: %s, Age: %d, Height: %.1f\n", john.name, john.age, john.height);

    return 0;
}
