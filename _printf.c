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
	size_t len;
	const char *str;
	va_list args;
	va_start(args, format);

	if (format == NULL)
		return -1;

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
		}
		switch (*format)
		{
			case 'c':
				c = va_arg(args, int);
				result += write(1, &c, 1);
				break;
			case 's':
				str = va_arg(args, const char *);
				if (str == NULL)
					return -1;
				else
				{
					len = strlen(str);
					result += write(1, str, len);
				}
				break;
			case '%':
				result += write(1, "%", 1);
				break;
			default:
				break;
		}
		format++;
	}
	va_end(args);
	return (result);
}
