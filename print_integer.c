#include "main.h"
/**
 * printf_i - funtion that prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_i(va_list args)
{
	int m = va_arg(args, int);
	int number, l = m % 10, d, exp = 1;
	int  k = 1;

	m = m / 10;
	number = m;
	if (l < 0)
	{
		_putchar('-');
		number = -number;
		m = -m;
		l = -l;
		k++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			exp = exp * 10;
			number = number / 10;
		}
		number = m;
		while (exp > 0)
		{
			d = number / exp;
			_putchar(d + '0');
			number = number - (d * exp);
			exp = exp / 10;
			k++;
		}
	}
	_putchar(l + '0');
	return (k);
}

/**
 * printf_decimal - function that prints decimal
 * @args: argument to print
 *
 * Return: number of printed characters
 */
int printf_decimal(va_list args)
{
	int m = va_arg(args, int);
	int number, l = m % 10, d;
	int  k = 1;
	int exp = 1;

	m = m / 10;
	number = m;
	if (l < 0)
	{
		_putchar('-');
		number = -number;
		m = -m;
		l = -l;
		k++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			exp = exp * 10;
			number = number / 10;
		}
		number = m;
		while (exp > 0)
		{
			d = number / exp;
			_putchar(d + '0');
			number = number - (d * exp);
			exp = exp / 10;
			k++;
		}
	}
	_putchar(l + '0');
	return (k);
}
