#include "main.h"

/**
 * _strncpy - Copy strings based on number of bytes
 * @dest: pointer to the destination string
 * @src: pointer to the sourc string
 * @n: number of bytes to be copied
 * Return: the pointer to dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; i < n && src[i]; i++)
		dest[i] = src[i];
	/* Fill the remaining chars in dest with null bytes */
	while (i < n)
		dest[i++] = '\0';

	return (dest);
}
