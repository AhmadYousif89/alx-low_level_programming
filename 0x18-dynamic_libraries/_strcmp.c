#include "main.h"

/**
 * _strcmp - Compare two strings
 * @s1: pointer of type char *
 * @s2: pointer of type char *
 * Return: the ascii difference number.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++, s2++;
	}

	return (*s1 - *s2);
}
