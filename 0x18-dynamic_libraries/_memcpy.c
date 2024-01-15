#include "main.h"

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

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
