#include <stdio.h>

/**
 * _strpbrk - Search a string for any set of bytes
 * @s: pointer type char
 * @accept: pointer type char
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}
	return (NULL);
}
