#include "main.h"
/**
 * printf_unsignd - prints unsigned integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_unsignd(va_list args)
{
	unsigned int nm = va_arg(args, unsigned int);
	int n, l = nm % 10, digit, exp = 1;
	int  k = 1;

	nm = nm / 10;
	n = nm;
	if (l < 0)
	{
		_putchar('-');
		n = -n;
		nm = -nm;
		l = -l;
		k++;
	}
	if (n > 0)
	{
		while (n / 10 != 0)
		{
			exp = exp * 10;
			n = n / 10;
		}
		n = nm;
		while (exp > 0)
		{
			digit = n / exp;
			_putchar(digit + '0');
			n = n - (digit * exp);
			exp = exp / 10;
			k++;
		}
	}
	_putchar(l + '0');
	return (k);
}
