#include <stdio.h>

struct Person {
    char *name;
    int age;
    float height;
};

// Function to modify the struct (by value)
void person_modify(struct Person p) {
    p.age = 35;  // Modify the age of the copied struct
    printf("Inside person_modify (by value):\n");
    person_print(p);
}

// Function to print the contents of the struct
void person_print(struct Person p) {
    printf("Name: %s, Age: %d, Height: %.1f\n", p.name, p.age, p.height);
}

int main(void) {
    struct Person john = {"John Doe", 30, 5.9};

    printf("Before person_modify (by value):\n");
    person_print(john);

    person_modify(john);  // Pass by value

    printf("After person_modify (by value):\n");
    person_print(john);  // Original struct remains unchanged

    return 0;
}
