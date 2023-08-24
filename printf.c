#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Print formatted output
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            if (format[i] == 'c')
            {
                count += print_char(args);
            }
            else if (format[i] == 's')
            {
                count += print_string(args);
            }
            else if (format[i] == '%')
            {
                count += _putchar('%');
            }
            else
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);

    return (count);
}

/**
 * print_char - Print a character
 * @args: va_list containing the character argument
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));
}
