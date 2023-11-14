#include "main.h"

/**
 * printf_octal - function prints an octal number.
 * @args: arguments.
 * Return: count
 */
int printf_octal(va_list args)
{
	int j;
	int *arr;
	int count = 0;

	unsigned int number = va_arg(args, unsigned int);
	unsigned int temp = number;

	while (number / 8 != 0)
	{
		number /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));
	for (j = 0; j < count; j++)
	{
		arr[j] = temp % 8;
		temp /= 8;
	}
	for (j = count - 1; j >= 0; j--)
	{
		_putchar(arr[j] + '0');
	}
	free(arr);
	return (count);
}
