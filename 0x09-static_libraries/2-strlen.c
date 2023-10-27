#include <stdio.h>

/**
 * _strlen - Return the length of string
 * @s: pointer of type char *
 * Return: str_Length
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
