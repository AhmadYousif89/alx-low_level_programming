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
	int result = 0, sign = 1, i = 0;

	while (*s != '\0' && !(s[i] >= '0' && s[i] <= '9'))
	{
		if (s[i] == '-')
			sign = sign * -1;
		i++;
	}

	while (*s != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		/* Convert string to integer */
		result = result * 10;
		result = result + (s[i] - '0');
		i++;
	}

	result = result * sign;

	return (result);
}
