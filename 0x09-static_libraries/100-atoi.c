#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 * _atoi - Convert string to integer
 * @s: data of type char *
 * Return: int result.
 */

int _atoi(char *s)
{
	unsigned int result = 0;
	int sign = 1, i = 0;

	/* Skip non-digit characters */
	while (s[i] != '\0' && !(s[i] >= '0' && s[i] <= '9'))
	{
		/* Negate the final result if we encounter (-) sign */
		if (s[i] == '-')
			sign = sign * -1;
		i++;
	}

	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		/* Convert string to integer */
		result = result * 10;
		result = result + (s[i] - '0');
		i++;
	}

	result = result * sign;

	return (result);
}
