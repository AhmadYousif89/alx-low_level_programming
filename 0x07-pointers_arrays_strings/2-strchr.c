#include <stdio.h>

/**
 * _strchr - Print a string from a given position
 * @s: pointer type char
 * @c: char
 * Return: Pointer to the memory area (s)
 */
char *_strchr(char *s, char c)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			/* Return the pointer from the position where 'c' is found */
			return (&s[i]);
		i++;
	}
	return (NULL);
}
