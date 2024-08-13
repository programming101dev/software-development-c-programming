#include <stdio.h>
#include <stdlib.h>

struct Person {
    char *name;
    int age;
    float height;
};

void person_print(struct Person *p) {
    printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, p->height);
}

int main(void) {
    // Dynamically allocate memory for a Person struct
    struct Person *john = malloc(sizeof(struct Person));
    if (john == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Initialize the members of the struct
    john->name = "John Doe";
    john->age = 30;
    john->height = 5.9;

    // Print the contents of the struct
    person_print(john);

    // Free the allocated memory
    free(john);

    return 0;
}
