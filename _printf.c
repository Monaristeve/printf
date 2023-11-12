#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - this is a function that prints to standard output
 * @format: format by which function produces output
 * Return: the number of characters printed excluding the
 *  null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	int x, y = 0, z = 0;/*y=output to be printed while z=printed chars*/
	int width, flags, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[x], 1);*/
			z++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			width = get_width(format, &x, list);
			flags = get_flags(format, &x);
			precision = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			y = handle_print(format, &x, list, buffer,
					width, flags, precision, size);
			if (y == -1)
				return (-1);
			z += y;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (z);
}
/**
 * print_buffer - a function that prints the content of the buffer
 * @buffer: character array
 * @buff_ind: this is the index at which the next character is added
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

