#include "main.h"

/**
 * _strspn - Get the length of a prefix substring
 * @s: pointer to the string
 * @accept: pointer type char
 * Return: the number of bytes in the initial segment of (s)
 * which consist only of bytes from (accept)
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s)
	{
		const char *accept_cpy = accept; /* Reset the pointer */

		while (*accept_cpy)
		{
			if (*s == *accept_cpy)
			{
				count++;
				break;
			}
			accept_cpy++;
		}
		if (*accept_cpy == '\0') /* No match found */
			break;

		s++;
	}

	return (count);
}
