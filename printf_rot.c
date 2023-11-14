#include "main.h"
/**
 * printf_rot - a function that prints string to into buffer
 * @args: the type struct va_arg
 * Return:the count
 */
int printf_rot(va_list args)
{
	int x, y, count = 0;
	int l = 0;
	char *c = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (c == NULL)
		c = "(null)";
	for (x = 0; c[x]; x++)
	{
		l = 0;
		for (y = 0; alpha[y] && !l; y++)
		{
			if (c[x] == alpha[y])
			{
				_putchar(beta[y]);
				count++;
				l = 1;
			}
		}
		if (!l)
		{
			_putchar(c[x]);
			count++;
		}
	}
	return (count);
}
