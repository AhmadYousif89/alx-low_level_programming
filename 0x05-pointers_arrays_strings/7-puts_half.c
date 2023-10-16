#include "main.h"
#include <stdio.h>

/**
 * puts_half - Print half of a string using _putchar
 * @str: data of type char *
 * Return: void
 */

void puts_half(char *str)
{
	int i = 0, j, len;

	while (str[i] != '\0')
	{
		i++;
	}

	len = i;

	for (j = len / 2; j < len; j++)
	{
		_putchar(str[j]);
	}
	_putchar('\n');
}
