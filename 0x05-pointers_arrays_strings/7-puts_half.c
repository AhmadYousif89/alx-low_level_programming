#include "main.h"
#include <stdio.h>

/**
 * puts_half - Print half of a string
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

	len = i - 1;

	for (j = 0; j <= len; j++)
	{
		if (j == len / 2)
		{
			break;
		}
		_putchar(str[j]);
	}
	_putchar('\n');
}
