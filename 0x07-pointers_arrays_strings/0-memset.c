#include <stdio.h>

/**
 * _memset - Print to memory string of buffer
 * @s: pointer type char
 * @b: char
 * @n: number
 * Return: Pointer to the memory area (s)
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
