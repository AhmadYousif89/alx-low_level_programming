#include <stdio.h>

/**
 * _strlen - Return the length of string
 * @s: pointer of type char *
 * Return: str_Length
 */

int _strlen(char *s)
{
	int i, str_length;

	for (i = 0; s[i] != '\0'; i++)
	{
		str_length++;
	}

	return (str_length);
}
