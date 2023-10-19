#include <stdio.h>
#include "main.h"

/**
 * rot13 - Convert string into (rot13)
 * @s: pointer type char *
 * Return: converted string (char *)
 */

char *rot13(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		while ((s[i] >= 'a' && s[i] <= 'z') ||
			   (s[i] >= 'A' && s[i] <= 'Z'))
		{
			if ((s[i] >= 'a' && s[i] <= 'm') ||
				(s[i] >= 'A' && s[i] <= 'M'))
				s[i] += 13;
			else
				s[i] -= 13;
			i++;
		}
	}

	return (s);
}
