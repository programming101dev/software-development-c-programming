#ifndef STRING_CONVERSIONS_H
#define STRING_CONVERSIONS_H

#include <stdbool.h>
#include <inttypes.h>  // For intmax_t and uintmax_t

// Functions for standard types
int string_to_int(const char *restrict str, int base, int *error);
long string_to_long(const char *restrict str, int base, int *error);
long long string_to_long_long(const char *restrict str, int base, int *error);
unsigned int string_to_unsigned_int(const char *restrict str, int base, int *error);
unsigned long string_to_unsigned_long(const char *restrict str, int base, int *error);
unsigned long long string_to_unsigned_long_long(const char *restrict str, int base, int *error);
float string_to_float(const char *restrict str, int *error);
double string_to_double(const char *restrict str, int *error);
long double string_to_long_double(const char *restrict str, int *error);

// Functions for char types
char string_to_char(const char *restrict str, int base, int *error);
signed char string_to_signed_char(const char *restrict str, int base, int *error);
unsigned char string_to_unsigned_char(const char *restrict str, int base, int *error);

// Functions for short types
short string_to_short(const char *restrict str, int base, int *error);
unsigned short string_to_unsigned_short(const char *restrict str, int base, int *error);

// Functions for fixed-width integer types
int8_t string_to_int8(const char *restrict str, int base, int *error);
uint8_t string_to_uint8(const char *restrict str, int base, int *error);
int16_t string_to_int16(const char *restrict str, int base, int *error);
uint16_t string_to_uint16(const char *restrict str, int base, int *error);
int32_t string_to_int32(const char *restrict str, int base, int *error);
uint32_t string_to_uint32(const char *restrict str, int base, int *error);
int64_t string_to_int64(const char *restrict str, int base, int *error);
uint64_t string_to_uint64(const char *restrict str, int base, int *error);

#endif // STRING_CONVERSIONS_H
