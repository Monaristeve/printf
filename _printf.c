#include "main.h"
/**
 * _printf - this is a function that prints a given format
 * @format:the  identifier to look for.
 * Return: characters
 */
int _printf(const char * const format, ...)
{
	convert p[] = {
		{"%s", printf_strng}, {"%c", printf_character},
		{"%%", printf_per},
		{"%i", printf_i}, {"%d", printf_d}, {"%r", printf_rev},
		{"%R", printf_rot}, {"%b", printf_binary}, {"%u", printf_unsignd},
		{"%o", printf_octal}, {"%x", printf_hexl}, {"%X", printf_HEXU},
		{"%S", printf_ex_strng}, {"%p", printf_ptr}
	};

	va_list args;
	int x = 0, y, length = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[x] != '\0')
	{
		y = 13;
		while (y >= 0)
		{
			if (p[y].id[0] == format[x] && p[y].id[1] == format[x + 1])
			{
				length += p[y].f(args);
				x = x + 2;
				goto Here;
			}
			y--;
		}
		_putchar(format[x]);
		length++;
		x++;
	}
	va_end(args);
	return (length);
}
