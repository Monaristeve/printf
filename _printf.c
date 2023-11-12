#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - function that produces output
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int result = 0;
	char c;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
		}
		switch (*format)
		{
			case 'c':
				c = va_arg(args, int);
				result += write(1, &c, 1);
				break;
			case 's':
				result += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
				break;
			case '%':
				result += write(1, "%", 1);
				break;
			default:
				break;
		}
		else
		{
			write(1, format, 1);
			result++;
		}
		format++;
	}
	va_end(args);
	return (result);
}
