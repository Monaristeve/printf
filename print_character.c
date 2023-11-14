#include "main.h"

/**
 * printf_character - function that prints a character
 * @val: list pf argument
 *
 * Return: 1 when succesfull
 */
int printf_character(va_list val)
{
	char c;
	
	c = va_arg(val, int);
	_putchar(c);
	return (1);
}
