#include "main.h"

/**
 * printf_rev - function that prints a str in reverse
 * @args: type struct va_arg where is allocated printf arguments
 * Return: the string
 */
int printf_rev(va_list args)
{
	char *str = va_arg(args, char*);
	int j;
	int k = 0;

	if (str == NULL)
		str = "(null)";
	while (str[k] != '\0')
		k++;
	for (j = k - 1; j >= 0; j--)
		_putchar(str[j]);
	return (k);
}
