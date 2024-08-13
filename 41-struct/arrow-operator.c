#include <stdio.h>

struct Person {
    char *name;
    int age;
    float height;
};

int main(void) {
    struct Person john;
    struct Person *p = &john;  // p is a pointer to john

    p->name = "John Doe";
    p->age = 30;
    p->height = 5.9;

    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, p->height);

    return 0;
}
