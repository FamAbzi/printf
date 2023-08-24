#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024

int print_integer(int num);
void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;
	int printed = 0;
	int buff_index = 0;
	char buffer[BUFF_SIZE];

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '%')
			{
				buffer[buff_index++] = '%';
				if (buff_index == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_index);
					char_count += buff_index;
				}
			}
			else if (*format == 'c')
			{
				int ch = va_arg(args, int);
				buffer[buff_index++] = ch;
				if (buff_index == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_index);
					char_count += buff_index;
				}
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					buffer[buff_index++] = *str;
					str++;
					if (buff_index == BUFF_SIZE)
					{
						print_buffer(buffer, &buff_index);
						char_count += buff_index;
					}
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				printed = print_integer(num);
				char_count += printed;
			}
		}
		else
		{
			buffer[buff_index++] = *format;
			if (buff_index == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_index);
				char_count += buff_index;
			}
		}

		format++;
	}

	print_buffer(buffer, &buff_index);
	char_count += buff_index;

	va_end(args);

	return char_count;
}

int print_integer(int num)
{
	char buffer[32];
	int printed = 0;

	if (num < 0)
	{
		putchar('-');
		printed++;
		num = -num;
	}

	int i = 0;
	do
	{
		buffer[i++] = '0' + (num % 10);
		num /= 10;
		printed++;
	} while (num > 0);

	for (int j = i - 1; j >= 0; j--)
	{
		putchar(buffer[j]);
	}

	return printed;
}

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		for (int i = 0; i < *buff_ind; i++)
		{
			putchar(buffer[i]);
		}
	}

	*buff_ind = 0;
}

// For testing the code 
int main(void)
{
	int number = 123;
	char character = 'A';
	char string[] = "Hello, World!";

	_printf("Printing an integer: %d\n", number);
	_printf("Printing a character: %c\n", character);
	_printf("Printing a string: %s\n", string);

	return 0;
}
