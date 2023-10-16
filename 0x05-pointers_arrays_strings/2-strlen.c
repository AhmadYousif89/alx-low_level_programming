#include <stdio.h>

/**
 * _strlen - Return the length of string
 * @s: pointer of type char *
 * Return: str_Len
 */

int _strlen(char *s)
{
	int i, str_len;

	while (s[i] != '\0')
	{
		i++;
	}
	str_len = i;

	return (str_len);
}
