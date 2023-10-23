#include <stdio.h>
#include "main.h"

/**
 * _strchr - Locate character and print string from its position
 * @s: pointer type char
 * @c: char
 * Return: Pointer to the memory area (s)
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return ('\0');
}
