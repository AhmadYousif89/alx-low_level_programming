#include <stdio.h>

/**
 * _strchr - Print a string from a given position
 * @s: pointer type char
 * @c: char
 * Return: Pointer to the memory area (s)
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		/* Return the pointer from the position where 'c' is found */
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}
