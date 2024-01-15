#include "main.h"

/**
 * _puts - Print a string using _putchar ending with a newline
 * @str: pointer of type char *
 * Return: str_Length
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
		_putchar(str[i++]);

	_putchar('\n');
}
