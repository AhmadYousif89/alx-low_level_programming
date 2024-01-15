#include "main.h"

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

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
