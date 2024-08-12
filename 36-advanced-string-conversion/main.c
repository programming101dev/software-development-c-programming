#include "string_conversions.h"
#include <stdio.h>

void print_conversion_result(const char *str, int base) {
    int error;

    int int_result = string_to_int(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to int: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to int: %d\n", str, int_result);
    }

    long long_result = string_to_long(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to long: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to long: %ld\n", str, long_result);
    }

    long long long_long_result = string_to_long_long(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to long long: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to long long: %lld\n", str, long_long_result);
    }

    unsigned int uint_result = string_to_unsigned_int(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to unsigned int: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to unsigned int: %u\n", str, uint_result);
    }

    unsigned long ulong_result = string_to_unsigned_long(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to unsigned long: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to unsigned long: %lu\n", str, ulong_result);
    }

    unsigned long long ulong_long_result = string_to_unsigned_long_long(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to unsigned long long: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to unsigned long long: %llu\n", str, ulong_long_result);
    }

    char char_result = string_to_char(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to char: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to char: %c\n", str, char_result);
    }

    signed char schar_result = string_to_signed_char(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to signed char: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to signed char: %c\n", str, schar_result);
    }

    unsigned char uchar_result = string_to_unsigned_char(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to unsigned char: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to unsigned char: %c\n", str, uchar_result);
    }

    short short_result = string_to_short(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to short: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to short: %d\n", str, short_result);
    }

    unsigned short ushort_result = string_to_unsigned_short(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to unsigned short: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to unsigned short: %u\n", str, ushort_result);
    }

    float float_result = string_to_float(str, &error);
    if (error) {
        printf("Error converting \"%s\" to float: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to float: %f\n", str, float_result);
    }

    double double_result = string_to_double(str, &error);
    if (error) {
        printf("Error converting \"%s\" to double: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to double: %f\n", str, double_result);
    }

    long double long_double_result = string_to_long_double(str, &error);
    if (error) {
        printf("Error converting \"%s\" to long double: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to long double: %Lf\n", str, long_double_result);
    }

    int8_t int8_result = string_to_int8(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to int8_t: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to int8_t: %" PRId8 "\n", str, int8_result);
    }

    uint8_t uint8_result = string_to_uint8(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to uint8_t: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to uint8_t: %" PRIu8 "\n", str, uint8_result);
    }

    int16_t int16_result = string_to_int16(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to int16_t: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to int16_t: %" PRId16 "\n", str, int16_result);
    }

    uint16_t uint16_result = string_to_uint16(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to uint16_t: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to uint16_t: %" PRIu16 "\n", str, uint16_result);
    }

    int32_t int32_result = string_to_int32(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to int32_t: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to int32_t: %" PRId32 "\n", str, int32_result);
    }

    uint32_t uint32_result = string_to_uint32(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to uint32_t: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to uint32_t: %" PRIu32 "\n", str, uint32_result);
    }

    int64_t int64_result = string_to_int64(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to int64_t: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to int64_t: %" PRId64 "\n", str, int64_result);
    }

    uint64_t uint64_result = string_to_uint64(str, base, &error);
    if (error) {
        printf("Error converting \"%s\" to uint64_t: %d\n", str, error);
    } else {
        printf("Converted \"%s\" to uint64_t: %" PRIu64 "\n", str, uint64_result);
    }
}

int main(void) {
    const char *test_cases[] = {
        "",
        "123",
        "ABC",
        "123abc"
    };

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        print_conversion_result(test_cases[i], 10);
    }

    return 0;
}
