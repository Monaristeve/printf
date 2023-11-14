#include "main.h"
/**
 * printf_binary - a function that prints a binary number
 * @val: list of arguments
 * Return: 1 when succesful
 */
int printf_binary(va_list val)
{
	int flag = 0;
	int count = 0;
	int j, x = 1, z;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int m;

	for (j = 0; j < 32; j++)
	{
		m = ((x << (31 - j)) & num);
		if (m >> (31 - j))
			flag = 1;
		if (flag)
		{
			z = m >> (31 - j);
			_putchar(z + 48);
			count++;
		}
	}
	if (count == 0)
	{
		count++;
		_putchar('0');
	}
	return (count);
}
