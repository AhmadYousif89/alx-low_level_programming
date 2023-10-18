#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _strncpy - Copy strings based on a given number
 * @dest: pointer of type char *
 * @src: pointer of type char *
 * @n: number of type int
 * Return: the pointer to dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		if (i < n)
			dest[i] = src[i];
	}
	/* If the length of src is less than (n), add null-terminate to dest */
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}

	return (dest);
}
