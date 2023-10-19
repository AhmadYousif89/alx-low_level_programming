#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * is_separator - Check for special chars
 * @c: char
 * Return: 1 or 0
 */
int is_separator(char c)
{
	int i;
	char separators[] = " \t\n,;.!?\"(){}";

	for (i = 0; separators[i] != '\0'; ++i)
	{
		if (c == separators[i])
			return (1);
	}
	return (0);
}

/**
 * toUpper - Convert char to uppercase
 * @c: char
 * Return: char
 */
char toUpper(char c)
{
	if (c >= 'a' && c <= 'z')
		return ((c) - 'a' + 'A');
	else
		return (c);
}

/**
 * cap_string - Capitalize all words for a given string
 * @s: pointer of type char *
 * Return: pointer to the string.
 */

char *cap_string(char *s)
{
	int i, len = strlen(s);
	int cap_next = 1;

	for (i = 0; i < len; ++i)
	{
		if (is_separator(s[i]))
			cap_next = 1;
		else if (cap_next)
		{
			s[i] = toUpper(s[i]);
			cap_next = 0;
		}
	}
	return (s);
}
