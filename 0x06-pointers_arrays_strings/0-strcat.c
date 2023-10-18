#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _strcat - Append a string to another string
 * @dest: pointer of type char *
 * @src: pointer of type char *
 * Return: the pointer to dest.
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int destLen = strlen(dest);

	for (i = 0; src[i] != '\0'; ++i)
	{
		dest[destLen + i] = src[i];
	}

	dest[destLen + i] = '\0';

	return (dest);
}
