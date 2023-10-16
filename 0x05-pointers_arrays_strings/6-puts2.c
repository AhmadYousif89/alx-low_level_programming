#include "main.h"
#include <stdio.h>

/**
 * puts2 - Print every other number
 * @str: data of type char *
 * Return: void
 */

void puts2(char *str)
{
	int i = 0, j, len;

	while (str[i] != '\0')
	{
		i++;
	}

	len = i - 1;

	for (j = 0; j <= len; j++)
	{
		if (j % 2 == 0)
		{
			_putchar(str[j]);
		}
	}
	_putchar('\n');
}
