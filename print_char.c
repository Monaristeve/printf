#include "main.h"

/**
 * print_char - a function that prints a character
 * @types: argument list
 * @buffer: this is buffer array
 * @flags:  this calculates the active flags
 * @width: calculates the width
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * Return: characters printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char y = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - a function that prints a string
 * @types: argument list
 * @buffer: this is buffer array
 * @flags:  this calculates the active flags
 * @width: calculates the width
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * Return: characters printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, j;
	char *string = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(precision);
	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}
	while (string[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], length);
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			write(1, &string[0], length);
			return (width);
		}
	}

	return (write(1, string, length));
}
/**
 * print_percent - a function that prints a percentage sign
 * @types: arguments list
 * @buffer: this is the buffer array
 * @flags:  this calculates the active flags
 * @width: finds the width
 * @precision: this is a precision specifier
 * @size: this is a size specifier
 * Return: characters printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - a function that prints an int
 * @types: arguments list
 * @buffer: this is the buffer array
 * @flags:  this calculates the active flags
 * @width: finds the width
 * @precision: this is a precision specifier
 * @size: this is a size specifier
 * Return: character printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFFER_SIZE - 2;
	int negative = 0;
	long int x = va_arg(types, long int);
	unsigned long int num;

	x = size_number(x, size);

	if (x == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	number = (unsigned long int)x;

	if (x < 0)
	{
		number = (unsigned long int)((-1) * x);
		negative = 1;
	}

	while (number > 0)
	{
		buffer[y--] = (number % 10) + '0';
		number /= 10;
	}

	y++;

	return (write_number(negative, y, buffer, flags, width, precision, size));
}
/**
 * print_binary - a function that prints an unsigned int
 * @types: arguments list
 * @buffer: this is the buffer array
 * @flags:  this calculates the active flags
 * @width: finds the width
 * @precision: this is a precision specifier
 * @size: this is a size specifier
 * Return: character number
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int p, s, z, addition;
	unsigned int x[32];
	int total;

	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(buffer);
	UNUSED(size);

	p = va_arg(types, unsigned int);
	s = 2147483648; /* (2 ^ 31) */
	x[0] = p / s;
	for (z = 1; z < 32; z++)
	{
		s /= 2;
		x[z] = (p / s) % 2;
	}
	for (z = 0, addition = 0, total = 0; z < 32; z++)
	{
		sum += x[z];
		if (addition || z == 31)
		{
			char a = '0' + x[z];

			write(1, &a, 1);
			total++;
		}
	}
	return (total);
}

