#include "main.h"
/**
 * _strlen - Returns the lenght of a string.
 * @str: Type char pointer
 * Return: character
 */
int _strlen(char *str)
{
	int c;

	for (c = 0; str[c] != 0; c++)
		;
	return (c);

}
/**
 * _strlenc - strlen function but constant character
 * @str: Type char pointer
 * Return: character
 */
int _strlenc(const char *str)
{
	int c;

	for (c = 0; str[c] != 0; c++)
		;
	return (c);
}
