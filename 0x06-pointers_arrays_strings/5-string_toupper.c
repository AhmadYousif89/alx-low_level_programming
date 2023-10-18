#include <stdio.h>
#include "main.h"

/**
 * string_toupper - Convert characters to uppercase
 * @s: pointer of type char *
 * Return: pointer to the string.
 */

char *string_toupper(char *s)
{
	int i;

	for (i = 1; s[i] != '\0'; i++)
	{
		if (s[i] > 90)
			s[i] -= 32;
	}

	return (s);
}
