#include "main.h"

/**
 * _puts - Print a string using _putchar
 * @str: pointer of type char *
 * Return: str_Length
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
