#include "main.h"

/**
 * binary_to_uint - Convert binary to positive number
 * @b: pointer to string of 0s and 1s
 * Return: -
 * The converted number or (0) if *b is NULL or contain char other than 1 or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int n = 0;

	if (!b)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		n = n * 2 + (b[i] - '0');
		i++;
	}

	return (n);
}
