#include "main.h"

/**
 * _strpbrk - Search a string for any set of bytes
 * @s: pointer type char
 * @accept: pointer type char
 * Return: Pointer to the byte in (s) that matches one of the bytes in accept
 * or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}

	return (NULL);
}
