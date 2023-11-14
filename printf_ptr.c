#include "main.h"
/**
 * printf_ptr - a function prints a pointer
 * @val: arguments variable
 * Return: 0
 */
int printf_ptr(va_list val)
{
	void *m;
	char *c = "(nil)";
	long int l;
	int d;
	int j;

	m = va_arg(val, void*);
	if (m == NULL)
	{
		for (j = 0; c[j] != '\0'; j++)
		{
			_putchar(c[j]);
		}
		return (j);
	}

	l = (unsigned long int)m;
	_putchar('0');
	_putchar('x');
	d = printf_hex_aux(l);
	return (d + 2);
}
