#include "main.h"
/**
 * printf_HEX_auxilliary - a function that prints a hexadecimal number
 * @num: integer to be printed
 * Return:count
 */
int printf_HEX_auxilliary(unsigned int num)
{
	int j;
	int *arr;
	int count = 0;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
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
