#include "main.h"
/**
 * printf_strng - a function that print a string
 * @val: list of arguments
 * Return: length of s string
 */
int printf_strng(va_list val)
{
	char *c;
	int j, length;

	c = va_arg(val, char *);
	if (c == NULL)
	{
		c = "(null)";
		length = _strlen(s);
		for (j = 0; j < length; j++)
			_putchar(c[j]);
		return (length);
	}
	else
	{
		length = _strlen(c);
		for (j = 0; j < length; j++)
			_putchar(c[j]);
		return (length);
	}
}
