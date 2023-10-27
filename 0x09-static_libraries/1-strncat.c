#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _strncat - Concatonate two strings based on a given number
 * @dest: pointer of type char *
 * @src: pointer of type char *
 * @n: number of type int
 * Return: the pointer to dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int destLen = strlen(dest);

	for (i = 0; src[i] != '\0'; ++i)
	{
		if (i < n)
			dest[destLen + i] = src[i];
		else
			break;
	}

	dest[destLen + i] = '\0';

	return (dest);
}
