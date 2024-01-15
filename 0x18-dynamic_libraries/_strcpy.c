#include "main.h"

/**
 * _strcpy - Copy string from src to dest
 * @dest: data of type char *
 * @src: data of type char *
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j = 0;

	while (src[i])
		i++; /* Get length of src */

	for (j = 0; j < i; j++)
		dest[j] = src[j];

	dest[i] = '\0';

	return (dest);
}
