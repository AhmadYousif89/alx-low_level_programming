#include <stdio.h>
#include "main.h"

/**
 * rot13 - Convert string into (rot13)
 * @s: pointer type char *
 * Return: converted string (char *)
 */

char *rot13(char *s)
{
	int i = 0;
	char *p = s;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alpha_13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (*s)
	{
		for (i = 0; i <= 52; i++)
		{
			if (alphabet[i] == *s)
			{
				*s = alpha_13[i];
				break;
			}
		}
		s++;
	}
	return (p);
}
