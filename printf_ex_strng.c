#include "main.h"
/**
 * printf_ex_strng - print exclusuives string
 * @args: list of arguments
 * Return: the length of the string
 */

int printf_ex_strng(va_list args)
{
	char *str;
	int j, length = 0;
	int cast;

	str = va_arg(str, char *);

	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] < 32 || str[j] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			length = length + 2;
			cast = str[j];
			if (cast < 16)
			{
				_putchar('0');
				length++;
			}
			length = length + printf_HEX_auxilliary(cast);
		}
		else
		{
			_putchar(str[j]);
			length++;
		}
	}
	return (length);
}
