#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* for va_list */

/* Custom putchar function (not provided) */
int _putchar(char c);

/* Main _printf function */
int _printf(const char *format, ...);

/* Conversion specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hex_upper(va_list args);
int print_pointer(va_list args);
int print_string_custom(va_list args);
int print_reversed(va_list args);
int print_rot13(va_list args);

/* Flags and length modifiers */
int handle_plus_space_hash(const char *format, int i, int *flags);
int handle_length_modifier(const char *format, int i, int *length_modifier);
int handle_field_width(const char *format, int i, va_list args, int *width);
int handle_precision(const char *format, int i, va_list args, int *precision);

#endif /* MAIN_H */
