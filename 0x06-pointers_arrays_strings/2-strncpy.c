#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _strncpy - Copy multiple strings based on a given number
 * @dest: pointer of type char *
 * @src: pointer of type char *
 * @n: number of type int
 * Return: the pointer to dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;
	int destLen = strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		if (dest[destLen] == '\n')
			break;
		else if (i < n)
		{
			dest[i] = src[i];
		}
	}

	dest[destLen + i] = '\0';

	return (dest);
}
