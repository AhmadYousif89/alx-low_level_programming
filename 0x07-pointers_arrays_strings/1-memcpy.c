#include <stdio.h>

/**
 * _memcpy - Copy from memory string of buffer
 * @dest: pointer type char
 * @src: pointer type char
 * @n: number of bytes
 * Return: Pointer to the memory area (s)
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
