#include <stdio.h>
#include "main.h"

/**
 * leet - Convert string into leet encoding (1337)
 * @s: pointer type char *
 * Return: converted string (char *)
 */

char *leet(char *s)
{
	int i, j;
	char letters[] = "AaEeOoTtLl";
	char numbers[] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0';)
		{
			if (s[i] == letters[j])
				s[i] = numbers[j];
			j++;
		}
	}

	return (s);
}
