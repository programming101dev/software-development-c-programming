#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void)
{
    char               var_char;
    signed char        var_signed_char;
    unsigned char      var_unsigned_char;
    short              var_short;
    unsigned short     var_unsigned_short;
    int                var_int;
    unsigned int       var_unsigned_int;
    long               var_long;
    unsigned long      var_unsigned_long;
    long long          var_long_long;
    unsigned long long var_unsigned_long_long;
    float              var_float;
    double             var_double;
    long double        var_long_double;
    _Bool              var__Bool;
    bool               var_bool;
    _Atomic int        var_atomic_int;
    wchar_t            var_wchar_t;
    float _Complex var_float_complex;
    double _Complex var_double_complex;
    long double _Complex var_long_double_complex;

    printf("Size of char: %zu bytes\n", sizeof(var_char));
    printf("Size of signed char: %zu bytes\n", sizeof(var_signed_char));
    printf("Size of unsigned char: %zu bytes\n", sizeof(var_unsigned_char));
    printf("Size of short: %zu bytes\n", sizeof(var_short));
    printf("Size of unsigned short: %zu bytes\n", sizeof(var_unsigned_short));
    printf("Size of int: %zu bytes\n", sizeof(var_int));
    printf("Size of unsigned int: %zu bytes\n", sizeof(var_unsigned_int));
    printf("Size of long: %zu bytes\n", sizeof(var_long));
    printf("Size of unsigned long: %zu bytes\n", sizeof(var_unsigned_long));
    printf("Size of long long: %zu bytes\n", sizeof(var_long_long));
    printf("Size of unsigned long long: %zu bytes\n", sizeof(var_unsigned_long_long));
    printf("Size of float: %zu bytes\n", sizeof(var_float));
    printf("Size of double: %zu bytes\n", sizeof(var_double));
    printf("Size of long double: %zu bytes\n", sizeof(var_long_double));
    printf("Size of _Bool: %zu bytes\n", sizeof(var__Bool));
    printf("Size of bool: %zu bytes\n", sizeof(var_bool));
    printf("Size of _Atomic int: %zu bytes\n", sizeof(var_atomic_int));
    printf("Size of wchar_t: %zu bytes\n", sizeof(var_wchar_t));
    printf("Size of float _Complex: %zu bytes\n", sizeof(var_float_complex));
    printf("Size of double _Complex: %zu bytes\n", sizeof(var_double_complex));
    printf("Size of long double _Complex: %zu bytes\n", sizeof(var_long_double_complex));

    return EXIT_SUCCESS;
}
