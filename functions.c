#include "main.h"
/**
 * print_unsigned - function that prints an unsigned number
 * @types: arguments list
 * @buffer: buffer array
 * @flags:  this calculates active flags
 * @width: this finds the width
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * Return: printed chars number
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[y--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[y--] = (number % 10) + '0';
		number /= 10;
	}

	y++;

	return (write_unsgnd(0, y, buffer, flags, width, precision, size));
}

/**
 * print_octal - a function that prints an unsigned number in octal notation
 * @types: arguments list
 * @buffer: buffer array
 * @flags:  this Calculates active flags
 * @width: calculates width
 * @precision: the precision specifier
 * @size: the size specifier
 * Return: printed chars number
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int y = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[y--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[y--] = (number % 8) + '0';
		number /= 8;
	}
	if (flags & F_HASH && init_number != 0)
		buffer[y--] = '0';
	y++;
	return (write_unsgnd(0, y, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints unsigned numbers in hexadecimal notation
 * @types: arguments list
 * @buffer: buffer array
 * @flags:  gets active flags
 * @width: calculates he width
 * @precision: the precision specificier
 * @size:the size specifier
 * Return: characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * * @types: arguments list
 * @buffer: buffer array
 * @flags:  gets active flags
 * @width: calculates he width
 * @precision: the precision specificier
 * @size:the size specifier
 * Return: characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - a function that prints a hexadecimal number in lower/upper
 * @types: arguments list
 * @map_to: values to map the number to
 * @buffer: Buffer array.
 * @flags: this calculates active flags
 * @flag_ch: this calculates active flags
 * @width: get width
 * @precision: the precision specifier
 * @size: Size specifier
 * Return: chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int y = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[y--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[y--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_number != 0)
	{
		buffer[y--] = flag_ch;
		buffer[y--] = '0';
	}
	y++;
	return (write_unsgnd(0, y, buffer, flags, width, precision, size));
}

