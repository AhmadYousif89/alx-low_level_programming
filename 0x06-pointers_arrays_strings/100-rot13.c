#include <stdio.h>
#include "main.h"

/**
 * rot13 - Convert string into (rot13)
 * @s: pointer type char *
 * Return: converted string (char *)
 */

char *rot13(char *s)
{
	int i = 0, j;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; /* 52 letter */
	char alpha_13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (s[i])
	{
		for (j = 0; j <= 52; j++)
		{
			if (alphabet[j] == s[i])
			{
				s[i] = alpha_13[j];
				break;
			}
		}
		i++;
	}
	return (s);
}
