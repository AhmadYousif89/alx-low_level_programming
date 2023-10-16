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

	if (len % 2 == 0)
	{
		for (j = (len / 2); j < len;)
		{
			_putchar(str[j]);
			j++;
		}
	}
	else
	{
		for (j = (len / 2); j < len - 1;)
		{
			j++;
			_putchar(str[j]);
		}
	}
	_putchar('\n');
}
