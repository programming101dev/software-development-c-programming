#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void)
{
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of signed char: %zu bytes\n", sizeof(signed char));
    printf("Size of unsigned char: %zu bytes\n", sizeof(unsigned char));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of unsigned short: %zu bytes\n", sizeof(unsigned short));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of unsigned long: %zu bytes\n", sizeof(unsigned long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of unsigned long long: %zu bytes\n", sizeof(unsigned long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Size of _Bool: %zu bytes\n", sizeof(_Bool));
    printf("Size of bool: %zu bytes\n", sizeof(bool));
    printf("Size of _Atomic int: %zu bytes\n", sizeof(_Atomic int));
    printf("Size of wchar_t: %zu bytes\n", sizeof(wchar_t));
    printf("Size of float _Complex: %zu bytes\n", sizeof(float _Complex));
    printf("Size of double _Complex: %zu bytes\n", sizeof(double _Complex));
    printf("Size of long double _Complex: %zu bytes\n", sizeof(long double _Complex));

    return EXIT_SUCCESS;
}
