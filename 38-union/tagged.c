#include <stdio.h>
#include <stdlib.h>

enum data_type
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR
};

union data
{
    int   i;
    float f;
    char  c;
};

struct tagged_data
{
    enum data_type type;
    union data     value;
};

static void print_tagged_data(const struct tagged_data *td);

int main(void)
{
    struct tagged_data td;

    td.type    = TYPE_INT;
    td.value.i = 42;
    print_tagged_data(&td);

    td.type    = TYPE_FLOAT;
    td.value.f = 3.14F;
    print_tagged_data(&td);

    td.type    = TYPE_CHAR;
    td.value.c = 'A';
    print_tagged_data(&td);

    return EXIT_SUCCESS;
}

static void print_tagged_data(const struct tagged_data *td)
{
    switch(td->type)
    {
        case TYPE_INT:
            printf("Integer: %d\n", td->value.i);
            break;
        case TYPE_FLOAT:
            printf("Float: %.2f\n", (double)td->value.f);
            break;
        case TYPE_CHAR:
            printf("Char: %c\n", td->value.c);
            break;
        default:
            printf("Unknown type\n");
            break;
    }
}
