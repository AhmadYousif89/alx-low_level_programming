#include <stdio.h>
#include "main.h"

/**
 * print_rev - Print a string in reverse using _putchar
 * @str: data of type char *
 * Return: str_Length
 */

void print_rev(char *str)
{
	int i = 0, idx, str_len;

	while (str[i] != '\0')
	{
		i++;
	}

	str_len = i;

	for (idx = str_len - 1; idx >= 0; idx--)
	{
		_putchar(str[idx]);
	}
	_putchar('\n');
}
