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
	while (s[i] && !(s[i] >= '0' && s[i] <= '9'))
	{
		/* Negate the result if the (-) sign is found */
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	/* Convert string to integer */
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	/* Handle the result sign */
	result *= sign;

	return (result);
}
