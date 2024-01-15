#include "main.h"

/**
 * _strchr - Locate character and print string from its position
 * @s: pointer to the string to be searched
 * @c: the character to match
 * Return: Pointer to the memory area (s) or NULL
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	return (NULL);
}
