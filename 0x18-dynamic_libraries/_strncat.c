#include "main.h"

/**
 * _strncat - Concatonate two strings limited by a number of bytes
 * @dest: pointer to the destination string
 * @src: pointer to the sourc string
 * @n: number of bytes to be copied
 * Return: pointer to dest or NULL.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *dest_cpy = dest;

	if (!dest || !src || n < 0)
		return (NULL);

	while (*dest_cpy)
		dest_cpy++; /* Move to the end of dest */

	while (*src && n-- > 0)
	{
		*dest_cpy = *src;
		dest_cpy++, src++;
	}

	*dest_cpy = '\0';

	return (dest);
}
