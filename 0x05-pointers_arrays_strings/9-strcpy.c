#include <stdio.h>
#include "main.h"

/**
 * _strcpy - Copy string from src to dest
 * @dest: data of type char *
 * @src: data of type char *
 * Return: the pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0, j, src_len;

	while (src[i] != '\0')
	{
		i++;
	}

	src_len = i;

	for (j = 0; j < src_len; j++)
	{
		dest[j] = src[j];
	}

	return (dest);
}
