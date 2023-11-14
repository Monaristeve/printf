#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct format - the conversion specifiers for printf
 * @sp: pointer to conversion specifires
 * @f: pointer to function for conversion specifier
 *
 */
typedef struct format
{
	char *sp;
	int (*f)();
}covert;
int printf_HEXU(va_list args);
int printf_character(va_list val);
int printf_i(va_list args);
int printf_decimal(va_list args);
int printf_oct(va_list args);
int printf_rev(va_list args);
int _strlen(char *str);
int _strlenc(const char *str);
int printf_unsignd(va_list args);
int printf_per(void);
int printf_ex_strng(va_list args);
void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);
int _putchar(char c);

#endif
