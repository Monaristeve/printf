#include "main.h"

/**
 * printf_HEXU - prints an hexadecimal number
 * @args: arguments
 * Return: count
 */
int printf_HEXU(va_list args)
{
	int j;
	int *arr;
	int count = 0;
	unsigned int number = va_arg(args, unsigned int);
	unsigned int temp = number;

	while (number / 16 != 0)
	{
		number /= 16;
		count++;
	}
	count++;

	arr = malloc(count * sizeof(int));
	for (j = 0; j < count; j++)
	{
		arr[j] = temp % 16;
		temp /= 16;
	}
	for (j = count - 1; j >= 0; j--)
	{
		if (arr[j] > 9)
			arr[j] = arr[j] + 7;
		_putchar(arr[j] + '0');
	}
	free(arr);
	return (count);
}
