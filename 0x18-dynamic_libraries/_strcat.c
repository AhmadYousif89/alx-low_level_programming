#include "main.h"

/**
 * _strcat - Concatenate from the source to the destination string
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * Return: pointer to dest or NULL.
 */
char *_strcat(char *dest, char *src)
{
	char *dest_cpy = dest;

	if (!dest || !src)
		return (NULL);

	while (*dest_cpy != '\0')
		dest_cpy++;

	while (*src)
	{
		*dest_cpy = *src;
		dest_cpy++, src++;
	}

	*dest_cpy = '\0';

	return (dest);
}
