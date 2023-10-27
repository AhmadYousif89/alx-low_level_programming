#include <stdio.h>
#include "main.h"

/**
 * _strcmp - Compare two strings
 * @s1: pointer of type char *
 * @s2: pointer of type char *
 * Return: the ascii difference number.
 */

int _strcmp(char *s1, char *s2)
{
	unsigned int result = 0, i;

	for (i = 0; (s1[i] != '\0'); i++)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
		{
			result = s1[i] - s2[i];
			break;
		}
		else
			result = 0;
	}

	return (result);
}
